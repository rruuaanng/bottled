#ifndef NONGFU_SPRING_COMMON_Q_FIXED_H
#define NONGFU_SPRING_COMMON_Q_FIXED_H

#ifdef __cplusplus
extern "C" {
#endif

//
// import standard library
//
#include <stdint.h>
#include <stdbool.h>

//
// qfixed math constant
//
#define Q15_FIXED_SQRT3                 0xDDB4

//
// table of sin and cos function value
//
// note:
//  type            q15_fixed
//  interval        [0, pi/2]
//  index           [0, 255) => [0, 254]
#define SIN_COS_TABLE_SIZE               0xFF
#define SIN_COS_TABLE   { \
    0x0000,0x00C9,0x0192,0x025B,0x0324,0x03ED,0x04B6,0x057F,\
    0x0647,0x0710,0x07D9,0x08A2,0x096A,0x0A33,0x0AFB,0x0BC3,\
    0x0C8B,0x0D53,0x0E1B,0x0EE3,0x0FAB,0x1072,0x1139,0x1201,\
    0x12C8,0x138E,0x1455,0x151B,0x15E2,0x16A8,0x176D,0x1833,\
    0x18F8,0x19BD,0x1A82,0x1B47,0x1C0B,0x1CCF,0x1D93,0x1E56,\
    0x1F19,0x1FDC,0x209F,0x2161,0x2223,0x22E5,0x23A6,0x2467,\
    0x2528,0x25E8,0x26A8,0x2767,0x2826,0x28E5,0x29A3,0x2A61,\
    0x2B1F,0x2BDC,0x2C98,0x2D55,0x2E11,0x2ECC,0x2F87,0x3041,\
    0x30FB,0x31B5,0x326E,0x3326,0x33DE,0x3496,0x354D,0x3604,\
    0x36BA,0x376F,0x3824,0x38D8,0x398C,0x3A40,0x3AF2,0x3BA5,\
    0x3C56,0x3D07,0x3DB8,0x3E68,0x3F17,0x3FC5,0x4073,0x4121,\
    0x41CE,0x427A,0x4325,0x43D0,0x447A,0x4524,0x45CD,0x4675,\
    0x471C,0x47C3,0x4869,0x490F,0x49B4,0x4A58,0x4AFB,0x4B9E,\
    0x4C3F,0x4CE1,0x4D81,0x4E21,0x4EBF,0x4F5E,0x4FFB,0x5097,\
    0x5133,0x51CE,0x5269,0x5302,0x539B,0x5433,0x54CA,0x5560,\
    0x55F5,0x568A,0x571D,0x57B0,0x5842,0x58D4,0x5964,0x59F3,\
    0x5A82,0x5B10,0x5B9D,0x5C29,0x5CB4,0x5D3E,0x5DC7,0x5E50,\
    0x5ED7,0x5F5E,0x5FE3,0x6068,0x60EC,0x616F,0x61F1,0x6271,\
    0x62F2,0x6371,0x63EF,0x646C,0x64E8,0x6563,0x65DD,0x6657,\
    0x66CF,0x6746,0x67BD,0x6832,0x68A6,0x6919,0x698C,0x69FD,\
    0x6A6D,0x6ADC,0x6B4A,0x6BB8,0x6C24,0x6C8F,0x6CF9,0x6D62,\
    0x6DCA,0x6E30,0x6E96,0x6EFB,0x6F5F,0x6FC1,0x7023,0x7083,\
    0x70E2,0x7141,0x719E,0x71FA,0x7255,0x72AF,0x7307,0x735F,\
    0x73B5,0x740B,0x745F,0x74B2,0x7504,0x7555,0x75A5,0x75F4,\
    0x7641,0x768E,0x76D9,0x7723,0x776C,0x77B4,0x77FA,0x7840,\
    0x7884,0x78C7,0x7909,0x794A,0x798A,0x79C8,0x7A05,0x7A42,\
    0x7A7D,0x7AB6,0x7AEF,0x7B26,0x7B5D,0x7B92,0x7BC5,0x7BF8,\
    0x7C29,0x7C5A,0x7C89,0x7CB7,0x7CE3,0x7D0F,0x7D39,0x7D62,\
    0x7D8A,0x7DB0,0x7DD6,0x7DFA,0x7E1D,0x7E3F,0x7E5F,0x7E7F,\
    0x7E9D,0x7EBA,0x7ED5,0x7EF0,0x7F09,0x7F21,0x7F38,0x7F4D,\
    0x7F62,0x7F75,0x7F87,0x7F97,0x7FA7,0x7FB5,0x7FC2,0x7FCE,\
    0x7FD8,0x7FE1,0x7FE9,0x7FF0,0x7FF6,0x7FFA,0x7FFD,0x8000}

int32_t sin_cos_lut[SIN_COS_TABLE_SIZE + 1] = SIN_COS_TABLE;

//
// utils
//
#define max(x, y)                       ((x) > (y) ? (x): (y))
#define min(x, y)                       ((x) < (y) ? (x): (y))
#define diff(x, y)                      (max(x, y) - min(x, y))
#define __qfixed_is_neg(n)             ((n) & __get_symbol_bit()? 1: 0)
#define __to_qfixed(n, wf)             (int32_t)((n) * (1 << (wf)))
#define __get_symbol_bit()              (1 << ((sizeof(int32_t) * 8) - 1))

//
// qfixed structure
//
#define Q_FIXED_SIZE                    0x20
#define Q_FIXED_WF_15                   0x0F                // Q15
#define Q_FIXED_WF_14                   0x0E                // Q14
#define Q_FIXED_WF_12                   0x0C                // Q12
#define Q_FIXED_WF_7                    0x07                // Q7
typedef int32_t                         qfixed;

#define qfixed_var(name, fixed) \
    qfixed name = fixed
#define qfixed_fvar(name, n_float, wf) \
    qfixed name = __to_qfixed(n_float, wf)

#define qxx(n_float, wf)                __to_qfixed(n_float, wf)
#define q15(n_float)                    __to_qfixed(n_float, Q_FIXED_WF_15)
#define q14(n_float)                    __to_qfixed(n_float, Q_FIXED_WF_14)
#define q12(n_float)                    __to_qfixed(n_float, Q_FIXED_WF_12)
#define q7(n_float)                     __to_qfixed(n_float, Q_FIXED_WF_7)

//
// qfixed multiplying and dividing multiples of two
//
#define qfixed_mul2(fixed)             ((fixed) << (1))
#define qfixed_mul4(fixed)             ((fixed) << (2))
#define qfixed_mul8(fixed)             ((fixed) << (3))
#define qfixed_mul16(fixed)            ((fixed) << (4))
#define qfixed_mul32(fixed)            ((fixed) << (5))
#define qfixed_mul64(fixed)            ((fixed) << (6))

#define qfixed_div2(fixed)             ((fixed) >> (1))
#define qfixed_div4(fixed)             ((fixed) >> (2))
#define qfixed_div8(fixed)             ((fixed) >> (3))
#define qfixed_div16(fixed)            ((fixed) >> (4))
#define qfixed_div32(fixed)            ((fixed) >> (5))
#define qfixed_div64(fixed)            ((fixed) >> (6))


//
// float-point number convert to fixed-point number
//
// argument:
//  fixed    qfixed object ptr
//  n        float-point number
//  wf       bit width
static inline
void float_to_qfixed(
    qfixed *fixed,
    float n, int wf)
{
    if (wf > Q_FIXED_SIZE)
        wf = Q_FIXED_SIZE;

    *fixed = __to_qfixed(n, wf);
}
#define float_to_q15_fixed(n_float) ({ \
    qfixed __qfixed_val; \
    float_to_qfixed(&__qfixed_val, n_float, Q_FIXED_WF_15); \
    __qfixed_val; \
})
#define float_to_q14_fixed(n_float) ({ \
    qfixed __qfixed_val; \
    float_to_qfixed(&__qfixed_val, n_float, Q_FIXED_WF_14); \
    __qfixed_val; \
})
#define float_to_q12_fixed(n_float) ({ \
    qfixed __qfixed_val; \
    float_to_qfixed(&__qfixed_val, n_float, Q_FIXED_WF_12); \
    __qfixed_val; \
})
#define float_to_q7_fixed(n_float) ({ \
    qfixed __qfixed_val; \
    float_to_qfixed(&__qfixed_val, n_float, Q_FIXED_WF_7); \
    __qfixed_val; \
})

//
// fixed-point number convert to float-point number
//
// argument:
//  n        float-point number ptr
//  fixed    qfixed object
//  wf       bit width
static inline
int qfixed_to_float(float *n, qfixed fixed, int wf)
{
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

    *n = *(float *)&tmp;
    return 0;
}
#define q15_fixed_to_float(fixed) ({ \
    float __float_val; \
    qfixed_to_float(&__float_val, fixed, Q_FIXED_WF_15); \
    __float_val; \
})
#define q14_fixed_to_float(fixed) ({ \
    float __float_val; \
    qfixed_to_float(&__float_val, fixed, Q_FIXED_WF_14); \
    __float_val; \
})
#define q12_fixed_to_float(fixed) ({ \
    float __float_val; \
    qfixed_to_float(&__float_val, fixed, Q_FIXED_WF_12); \
    __float_val; \
})
#define q7_fixed_to_float(fixed) ({ \
    float __float_val; \
    qfixed_to_float(&__float_val, fixed, Q_FIXED_WF_7); \
    __float_val; \
})

//
// fixed-point number addition
//
// argument:
//  y        qfixed object ptr
//  x1       operand number1
//  x2       operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
static inline
void qfixed_add(
    qfixed *y, 
    qfixed x1, qfixed x2,
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

    *y = n1 + n2;
}
#define q15_fixed_add(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_add(&__qfixed_val, x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15); \
    __qfixed_val; \
})
#define q14_fixed_add(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_add(&__qfixed_val, x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14); \
    __qfixed_val; \
})
#define q12_fixed_add(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_add(&__qfixed_val, x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12); \
    __qfixed_val; \
})
#define q7_fixed_add(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_add(&__qfixed_val, x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7); \
    __qfixed_val; \
})
    


//
// fixed-point number subtraction
//
// argument:
//  y        qfixed object ptr
//  x1       operand number1
//  x2       operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
static inline
void qfixed_sub(
    qfixed *y, 
    qfixed x1, qfixed x2,
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

    *y = n1 - n2;
}
#define q15_fixed_sub(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_sub(&__qfixed_val, x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15); \
    __qfixed_val; \
})
#define q14_fixed_sub(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_sub(&__qfixed_val, x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14); \
    __qfixed_val; \
})
#define q12_fixed_sub(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_sub(&__qfixed_val, x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12); \
    __qfixed_val; \
})
#define q7_fixed_sub(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_sub(&__qfixed_val, x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7); \
    __qfixed_val; \
})
    

// fixed-point number multiplication
//
// argument:
//  y            qfixed object ptr
//  x1           operand number1
//  x2           operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
static inline
void qfixed_mul(
    qfixed *y,
    qfixed x1, qfixed x2, int wf)
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

    *y = (int_fast32_t)tmp;
}
#define q15_fixed_mul(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_mul(&__qfixed_val, x1, x2, Q_FIXED_WF_15); \
    __qfixed_val; \
})
#define q14_fixed_mul(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_mul(&__qfixed_val, x1, x2, Q_FIXED_WF_14); \
    __qfixed_val; \
})
#define q12_fixed_mul(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_mul(&__qfixed_val, x1, x2, Q_FIXED_WF_12); \
    __qfixed_val; \
})
#define q7_fixed_mul(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_mul(&__qfixed_val, x1, x2, Q_FIXED_WF_7); \
    __qfixed_val; \
})

//
// fixed-point number division
//
// argument:
//  y            qfixed object ptr
//  x1           operand number1
//  x2           operand number2
// note:
//  copy for IQmath (it's so hard)
static inline
void qfixed_div(
    qfixed *y,
    qfixed x1, qfixed x2, int wf)
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
    
    const uint8_t div_lut_q6[] = {
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
        *y = -(int_fast32_t)result;
    } else {
        *y = (int_fast32_t)result;
    }
    return ;

error:
    *y = 0;
}
#define q15_fixed_div(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_div(&__qfixed_val, x1, x2, Q_FIXED_WF_15); \
    __qfixed_val; \
})
#define q14_fixed_div(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_div(&__qfixed_val, x1, x2, Q_FIXED_WF_14); \
    __qfixed_val; \
})
#define q12_fixed_div(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_div(&__qfixed_val, x1, x2, Q_FIXED_WF_12); \
    __qfixed_val; \
})
#define q7_fixed_div(x1, x2) ({ \
    qfixed __qfixed_val; \
    qfixed_div(&__qfixed_val, x1, x2, Q_FIXED_WF_7); \
    __qfixed_val; \
})

//
// fixed-point number greater than comparison
//
// argument:
//  x1           operand number1
//  x2           operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
// return:
//  is x1 greater then x2
static inline
bool qfixed_gt(
    qfixed x1, qfixed x2,
    int x1_wf, int x2_wf)
{
    qfixed y;

    // i'm too smart
    qfixed_sub(&y, x1, x2, x1_wf, x2_wf);
    
    if (y > 0)
        return true;
    return false;
}
#define q15_fixed_gt(x1, x2) \
    qfixed_gt(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_gt(x1, x2) \
    qfixed_gt(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_gt(x1, x2) \
    qfixed_gt(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_gt(x1, x2) \
    qfixed_gt(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number greater than comparison with equal
//
// argument:
//  x1           operand number1
//  x2           operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
// return:
//  is x1 greater than or equal to x2
static inline
bool qfixed_gte(
    qfixed x1, qfixed x2,
    int x1_wf, int x2_wf)
{
    qfixed y;

    // i'm too smart
    qfixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y >= 0)
        return true;
    return false;
}
#define q15_fixed_gte(x1, x2) \
    qfixed_gte(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_gte(x1, x2) \
    qfixed_gte(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_gte(x1, x2) \
    qfixed_gte(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_gte(x1, x2) \
    qfixed_gte(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number less than comparison
//
// argument:
//  x1           operand number1
//  x2           operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
// return:
//  is x1 less then x2
static inline
bool qfixed_lt(
    qfixed x1, qfixed x2,
    int x1_wf, int x2_wf)
{
    qfixed y;

    qfixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y < 0)
        return true;
    return false;
}
#define q15_fixed_lt(x1, x2) \
    qfixed_lt(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_lt(x1, x2) \
    qfixed_lt(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_lt(x1, x2) \
    qfixed_lt(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_lt(x1, x2) \
    qfixed_lt(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number less than comparison with equal
//
// argument:
//  x1           operand number1
//  x2           operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
// return:
//  is x1 less than or equal to x2
static inline
bool qfixed_lte(
    qfixed x1, qfixed x2,
    int x1_wf, int x2_wf)
{
    qfixed y;

    qfixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y <= 0)
        return true;
    return false;
}
#define q15_fixed_lte(x1, x2) \
    qfixed_lte(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_lte(x1, x2) \
    qfixed_lte(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_lte(x1, x2) \
    qfixed_lte(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_lte(x1, x2) \
    qfixed_lte(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number equal comparison
//
// argument:
//  x1           operand number1
//  x2           operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
// return:
//  is x1 equal to x2
static inline
bool qfixed_eq(
    qfixed x1, qfixed x2,
    int x1_wf, int x2_wf)
{
    qfixed y;

    qfixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y == 0)
        return true;
    return false;
}
#define q15_fixed_eq(x1, x2) \
    qfixed_eq(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_eq(x1, x2) \
    qfixed_eq(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_eq(x1, x2) \
    qfixed_eq(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_eq(x1, x2) \
    qfixed_eq(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number not equal comparison
//
// argument:
//  x1       operand number1
//  x2       operand number2
//  x1_wf    x1 bit width
//  x2_wf    x2 bit width
// return:
//  is x1 not equal to x2
static inline
bool qfixed_ne(
    qfixed x1, qfixed x2,
    int x1_wf, int x2_wf)
{
    qfixed y;

    qfixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y != 0)
        return true;
    return false;
}
#define q15_fixed_ne(x1, x2) \
    qfixed_ne(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_ne(x1, x2) \
    qfixed_ne(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_ne(x1, x2) \
    qfixed_ne(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_ne(x1, x2) \
    qfixed_ne(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// symbolic function
//
// argument:
//  x1       operand number1
// return:
//  symbolic of x1
static inline
int qfixed_math_sign(qfixed x1)
{
    if (__qfixed_is_neg(x1)) {
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
static inline
qfixed qfixed_math_abs(qfixed x1)
{
    if (__qfixed_is_neg(x1)) {
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
static inline
void qfixed_math_sin_cos_q15(
    qfixed *sin, qfixed *cos,
    int angle)
{
#define QUAD_0_90        0U
#define QUAD_90_180      1U
#define QUAD_180_270     2U
#define QUAD_270_360     3U
    int i;
    int quadrant;

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
//  y       qfixed object ptr
//  x1      operand number
static inline
void qfixed_math_sqrt(qfixed *y, qfixed x1);

//
// power function
//
// argument:
//  y       qfixed object ptr
//  x1      operand number
static inline
void qfixed_math_power(qfixed *y, qfixed x1);

//
// logarithmic function
//
// argument:
//  y       qfixed object ptr
//  x1      operand number1
static inline
void qfixed_math_log(qfixed *y, qfixed x1);

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_COMMON_Q_FIXED_H