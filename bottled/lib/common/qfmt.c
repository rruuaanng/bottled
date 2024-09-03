#include <common/qfmt.h>


//
// float-point number convert to fixed-point number
//
// argument:
//  n        float-point number
//  wf       bit width
// return:
//  fixed    qfmt object
qfmt float_to_qfmt(float n, int wf)
{
    if (wf > Q_FIXED_SIZE)
        wf = Q_FIXED_SIZE;

    return __to_qfmt(n, wf);
}

//
// fixed-point number convert to float-point number
//
// argument:
//  fixed    qfmt object
//  wf       bit width
// return:
//  n        float-point number ptr
float qfmt_to_float(qfmt fixed, int wf)
{
    float result;
    uint16_t offset;
    uint32_t tmp;
    uint32_t in_fixed;

    offset = 0x3f80 + ((31 - wf) * ((uint32_t)(1) << (23 - 16)));

    if (wf > Q_FIXED_SIZE)
        wf = Q_FIXED_SIZE;

    if (fixed < 0) {
        offset |= 0x8000;
        in_fixed = -fixed;
    } else if (fixed == 0) {
        return 1;
    } else {
        in_fixed = fixed;
    }

    while ((uint16_t)(in_fixed >> 16) < 0x8000) {
        in_fixed <<= 1;
        offset -= 0x0080;
    }

    tmp = (in_fixed + 0x0080) >> 8;
    tmp &= ~0x00800000;
    tmp += (uint32_t)offset << 16;

    result = *(float *)&tmp;
    return result;
}

// XXX: bit width
// fixed-point number addition
//
// argument:
//  x1       operand number1
//  x2       operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
// return:
//  y        qfmt object ptr
qfmt qfmt_add(
    qfmt x1, qfmt x2,
    int x1_wf, int x2_wf)
{
    int32_t n1, n2;
    int wf_diff;

    n1 = x1;
    n2 = x2;

    // align decimal places
    wf_diff = diff(x1_wf, x2_wf);
    if (x1_wf < x2_wf) {
        n1 <<= wf_diff;
    } else {
        n2 <<= wf_diff;
    }

    return n1 + n2;
}

//
// fixed-point number subtraction
//
// argument:
//  x1       operand number1
//  x2       operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
// return:
//  y        qfmt object ptr
qfmt qfmt_sub(
    qfmt x1, qfmt x2,
    int x1_wf, int x2_wf)
{
    int32_t n1, n2;
    int wf_diff;

    n1 = x1;
    n2 = x2;
    
    // align decimal places
    wf_diff = diff(x1_wf, x2_wf);
    if (x1_wf < x2_wf) {
        n2 <<= wf_diff;
    } else {
        n1 <<= wf_diff;
    }

    return n1 - n2;
}

// fixed-point number multiplication
//
// argument:
//  x1           operand number1
//  x2           operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
//  y            qfmt object ptr
qfmt qfmt_mul(
    qfmt x1, qfmt x2, int wf)
{
    int32_t x1_low, x2_low;
    int32_t x1_high, x2_high;
    int64_t x1_tmp, x2_tmp, tmp;

    x1_low = x1 & 0xFFFF;
    x2_low = x2 & 0xFFFF;
    x1_high = x1 >> 16;
    x2_high = x2 >> 16;

    // karatsuba algorithm
    tmp = x1_low * x2_low;
    tmp += (int_fast64_t)(x1_high * x2_low + x1_low * x2_high) << 16;
    tmp += (int_fast64_t)(x1_high * x2_high) << 32;
    tmp >>= wf;

    return (int_fast32_t)tmp;
}

//
// fixed-point number division
//
// argument:
//  x1           operand number1
//  x2           operand number2
// return:
//  qfmt object
// note:
//  copy for IQmath (it's so hard)
qfmt qfmt_div(
    qfmt x1, qfmt x2, int wf)
{
#define ____right(x1, x2)              (uint_fast32_t)(((uint_fast64_t)x1 * (uint_fast64_t)x2) >> 31)
#define ____sub_tmp(tmp)               (-((uint_fast32_t)tmp - 0x80000000))
    uint8_t idx, symb_flag = 0;
    uint_fast32_t tmp;
    uint_fast32_t div_factor;
    uint_fast32_t x1_tmp_q32;
    uint_fast32_t x2_tmp_q32;
    uint_fast32_t result;
    uint_fast64_t x1_tmp_q64;
    
    static const uint8_t div_lut_q6[] = {
        0x7F, 0x7D, 0x7B, 0x79, 0x78, 0x76, 0x74, 0x73, 
        0x71, 0x6F, 0x6E, 0x6D, 0x6B, 0x6A, 0x68, 0x67, 
        0x66, 0x65, 0x63, 0x62, 0x61, 0x60, 0x5F, 0x5E, 
        0x5D, 0x5C, 0x5B, 0x5A, 0x59, 0x58, 0x57, 0x56, 
        0x55, 0x54, 0x53, 0x52, 0x52, 0x51, 0x50, 0x4F, 
        0x4E, 0x4E, 0x4D, 0x4C, 0x4C, 0x4B, 0x4A, 0x49, 
        0x49, 0x48, 0x48, 0x47, 0x46, 0x46, 0x45, 0x45, 
        0x44, 0x43, 0x43, 0x42, 0x42, 0x41, 0x41, 0x40,
        0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    
    // if the divisor is less than zero
    // mark it as a negative number
    if (x2 <= 0) {
        if (x2 == 0) {
            goto error;
        }
        else {
            symb_flag = 1;
            x2 = -x2;
        }
    }

    // if x1 is less than zero
    // take the absolute value of x1
    if (x1 < 0) {
        symb_flag ^= 1;
        x1 = -x1;
    }

    // convert to 64bit
    x1_tmp_q64 = (uint_fast64_t)x1;
    x2_tmp_q32 = (uint_fast32_t)x2;

    // if x2 is less than q15(32768)
    // scale to [0.5, 1]
    while (x2_tmp_q32 < 0x40000000) {
        x2_tmp_q32 <<= 1;
        x1_tmp_q64 <<= 1;
    }

    // restricted between q0 and q30
    if (wf < 31) {
        x1_tmp_q64 >>= (31 - wf - 1);
    }
    else {
        x1_tmp_q64 <<= 1;
    }

    // check overflow
    if (x1_tmp_q64 >> 32) {
        goto error;
    }
    else {
        x1_tmp_q32 = (uint_fast32_t)x1_tmp_q64;
    }

    // use the left seven digits
    idx = x2_tmp_q32 >> 24;
    idx -= 64;
    div_factor = (uint_fast32_t)div_lut_q6[idx] << 24;

    // 1
    tmp = ____right(div_factor, x2_tmp_q32);
    tmp = ____sub_tmp(tmp);;
    tmp = tmp << 1;
    div_factor = ____right(div_factor, tmp);

    // 2
    tmp = ____right(div_factor, x2_tmp_q32);
    tmp = ____sub_tmp(tmp);;
    tmp = tmp << 1;
    div_factor = ____right(div_factor, tmp);

    // 3
    tmp = ____right(div_factor, x2_tmp_q32);
    tmp = ____sub_tmp(tmp);
    tmp = tmp << 1;
    div_factor = ____right(div_factor, tmp);

    result = ____right(div_factor, x1_tmp_q32);

    if (result > INT32_MAX) {
        goto error;
    }

    // if the sign is negative
    // return negative number
    if (symb_flag) {
        return -(int_fast32_t)result;
    } else {
        return (int_fast32_t)result;
    }
    return 0;

error:
    return -1;
#undef ____right
#undef ____sub_tmp
}

//
// symbolic function
//
// argument:
//  x1       operand number1
// return:
//  symbolic of x1
int qfmt_math_sign(qfmt x1)
{
    if (__qfmt_is_neg(x1)) {
        return -1;
    } else if (x1 != 0){
        return 1;
    } else {
        return 0;
    }
}

//
// absolute value function
//
// argument:
//  x1       operand number1
// return:
//  absolute value of x1
qfmt qfmt_math_abs(qfmt x1)
{
    if (__qfmt_is_neg(x1)) {
        return x1 * -1;
    } else {
        return x1;
    }
}

//
// sin and cos function
//
// argument:
//  sin      sin value ptr
//  cos      cos value ptr
//  angle    measure angle
void qfmt_math_sin_cos_q15(
    qfmt *sin, qfmt *cos,
    int angle)
{
#define QUAD_0_90        0U
#define QUAD_90_180      1U
#define QUAD_180_270     2U
#define QUAD_270_360     3U
    int i;
    int quadrant;
    
    static const int32_t sin_cos_lut[] = SIN_COS_TABLE;

    angle %= 360;
    quadrant = angle / 90;

    i = (angle * SIN_COS_TABLE_SIZE / 90) % SIN_COS_TABLE_SIZE;

    switch (quadrant) {
    case QUAD_0_90:    // [0, 90°)
        *sin = sin_cos_lut[i];
        *cos = sin_cos_lut[SIN_COS_TABLE_SIZE - i];
        break;
    case QUAD_90_180:  // [90, 180°)
        *sin = sin_cos_lut[SIN_COS_TABLE_SIZE - i];
        *cos = -sin_cos_lut[i];
        break;
    case QUAD_180_270: // [180, 270°)
        *sin = -sin_cos_lut[i];
        *cos = -sin_cos_lut[SIN_COS_TABLE_SIZE - i];
        break;
    case QUAD_270_360: // [270, 360°]
        *sin = -sin_cos_lut[SIN_COS_TABLE_SIZE - i];
        *cos = sin_cos_lut[i];
        break;
    }
}

//
// square root function
//
// argument:
//  x1      operand number
// return:
//  qfmt object ptr
qfmt qfmt_math_sqrt(qfmt x1)
{
    return 0;
}

//
// power function
//
// argument:
//  x1      operand 
// return:
//  y       qfmt object ptr
void qfmt_math_power(qfmt *y, qfmt x1)
{
}

//
// logarithmic function
//
// argument:
//  x1      operand number1
// return:
//  y       qfmt object ptr
void qfmt_math_log(qfmt *y, qfmt x1)
{
}

//
// exponential function
// 
// argument:
//  x1      operand number1
// return:
//  y       qfmt object ptr
void qfmt_math_exp(qfmt *y, qfmt x1)
{
}