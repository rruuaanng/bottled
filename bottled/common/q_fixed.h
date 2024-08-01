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
// q_fixed math constant
//
#define Q15_FIXED_SQRT3                 0xDDB4

//
// table of sin and cos function value
// 
// TODO: to be optimized
// note:
//  type            q15_fixed
//  interval        [0, pi/2]
//  index           [0, 254) => [0, 253]
#define SIN_COS_TABLE_SIZE               0xFD
#define SIN_COS_TABLE   { \
    0x0,   0xCB,  0x196, 0x261, 0x329, 0x3F4, 0x4BF, 0x58A, \
    0x656, 0x71D, 0x7E9, 0x8B4, 0x97C, 0xA47, 0xB12, 0xBDA, \
    0xCA5, 0xD6D, 0xE38, 0xF00, 0xFCB, 0x1093,0x115B,0x1226, \
    0x12EE,0x13B6,0x147E,0x1546,0x160D,0x16D5,0x179D,0x1862, \
    0x192A,0x19F2,0x1AB6,0x1B7E,0x1C43,0x1D07,0x1DCC,0x1E94, \
    0x1F58,0x201A,0x20DE,0x21A3,0x2268,0x2329,0x23ED,0x24AF, \
    0x2570,0x2631,0x26F3,0x27B4,0x2875,0x2934,0x29F5,0x2AB3, \
    0x2B71,0x2C2F,0x2CED,0x2DAB,0x2E69,0x2F27,0x2FE2,0x309D, \
    0x3158,0x3212,0x32CD,0x3388,0x343F,0x34FA,0x35B2,0x3669, \
    0x3721,0x37D8,0x388C,0x3944,0x39F8,0x3AAC,0x3B61,0x3C15, \
    0x3CC6,0x3D77,0x3E2B,0x3ED9,0x3F8A,0x403A,0x40E8,0x4196, \
    0x4243,0x42F1,0x439F,0x4449,0x44F4,0x459E,0x4648,0x46F3, \
    0x479A,0x4841,0x48E8,0x498F,0x4A36,0x4ADA,0x4B7E,0x4C22, \
    0x4CC2,0x4D66,0x4E07,0x4EA7,0x4F45,0x4FE5,0x5083,0x5120, \
    0x51BD,0x5257,0x52F1,0x538B,0x5425,0x54BF,0x5556,0x55ED, \
    0x5680,0x5717,0x57AA,0x583E,0x58D1,0x5961,0x59F2,0x5A82, \
    0x5B12,0x5B9F,0x5C2C,0x5CB9,0x5D42,0x5DCF,0x5E56,0x5EDF, \
    0x5F65,0x5FEF,0x6072,0x60F9,0x617C,0x61FF,0x6282,0x6302, \
    0x6381,0x6401,0x647E,0x64FA,0x6577,0x65F3,0x666C,0x66E6, \
    0x675F,0x67D5,0x684B,0x68C1,0x6934,0x69A6,0x6A19,0x6A88, \
    0x6AF8,0x6B67,0x6BD7,0x6C43,0x6CAF,0x6D18,0x6D81,0x6DE9, \
    0x6E52,0x6EB8,0x6F1D,0x6F80,0x6FE5,0x7044,0x70A7,0x7106, \
    0x7165,0x71C0,0x721F,0x727B,0x72D4,0x732C,0x7385,0x73DA, \
    0x7432,0x7484,0x74D9,0x752B,0x757D,0x75CC,0x761B,0x7669, \
    0x76B5,0x7700,0x7748,0x7793,0x77DB,0x7820,0x7865,0x78AA, \
    0x78EF,0x7930,0x796F,0x79B0,0x79EE,0x7A29,0x7A68,0x7AA3, \
    0x7ADA,0x7B12,0x7B4A,0x7B81,0x7BB6,0x7BE7,0x7C1B,0x7C4D, \
    0x7C7A,0x7CA8,0x7CD6,0x7D04,0x7D2F,0x7D56,0x7D81,0x7DA8, \
    0x7DCC,0x7DF3,0x7E14,0x7E38,0x7E59,0x7E7A,0x7E97,0x7EB5, \
    0x7ED2,0x7EEC,0x7F06,0x7F1D,0x7F34,0x7F4B,0x7F5F,0x7F73, \
    0x7F86,0x7F97,0x7FA4,0x7FB4,0x7FC1,0x7FCE,0x7FD8,0x7FE2, \
    0x7FE9,0x7FEF,0x7FF6,0x7FF9,0x7FFC,0x8000}

int32_t sin_cos_lut[SIN_COS_TABLE_SIZE + 1] = SIN_COS_TABLE;

//
// utils
//
#define max(x, y)                       ((x) > (y) ? (x): (y))
#define min(x, y)                       ((x) < (y) ? (x): (y))
#define diff(x, y)                      (max(x, y) - min(x, y))
#define __q_fixed_is_neg(n)             ((n) & __get_symbol_bit()? 1: 0)
#define __to_q_fixed(n, wf)             (int32_t)((n) * (1 << (wf)))
#define __get_symbol_bit()              (1 << ((sizeof(int32_t) * 8) - 1))

//
// q_fixed structure
//
#define Q_FIXED_SIZE                    0x20
#define Q_FIXED_WF_15                   0x0F                // Q15
#define Q_FIXED_WF_14                   0x0E                // Q14
#define Q_FIXED_WF_12                   0x0C                // Q12
#define Q_FIXED_WF_7                    0x07                // Q7
typedef int32_t                         q_fixed;

#define q_fixed_var(name, fixed) \
    q_fixed name = fixed

#define q15(n_float)                    __to_q_fixed(n_float, Q_FIXED_WF_15)
#define q14(n_float)                    __to_q_fixed(n_float, Q_FIXED_WF_14)
#define q12(n_float)                    __to_q_fixed(n_float, Q_FIXED_WF_12)
#define q7(n_float)                     __to_q_fixed(n_float, Q_FIXED_WF_7)

//
// float-point number convert to fixed-point number
//
// argument:
// fixed    q_fixed object ptr
// n        float-point number
// wf       bit width
static inline
void float_to_q_fixed(
    q_fixed *fixed,
    float n, int wf)
{
    if (wf > Q_FIXED_SIZE)
        wf = Q_FIXED_SIZE;

    *fixed = __to_q_fixed(n, wf);
}
#define float_to_q15_fixed(q_fixed_ptr, n_float) \
    float_to_q_fixed(q_fixed_ptr, n_float, Q_FIXED_WF_15)
#define float_to_q14_fixed(q_fixed_ptr, n_float) \
    float_to_q_fixed(q_fixed_ptr, n_float, Q_FIXED_WF_14)
#define float_to_q12_fixed(q_fixed_ptr, n_float) \
    float_to_q_fixed(q_fixed_ptr, n_float, Q_FIXED_WF_12)
#define float_to_q7_fixed(q_fixed_ptr, n_float) \
    float_to_q_fixed(q_fixed_ptr, n_float, Q_FIXED_WF_7)

//
// fixed-point number convert to float-point number
//
// argument:
// n        float-point number ptr
// fixed    q_fixed object
static inline
int q_fixed_to_float(float *n, q_fixed fixed, int wf)
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
#define q15_fixed_to_float(float_ptr, fixed) \
    q_fixed_to_float(float_ptr, fixed, Q_FIXED_WF_15)
#define q14_fixed_to_float(float_ptr, fixed) \
    q_fixed_to_float(float_ptr, fixed, Q_FIXED_WF_14)
#define q12_fixed_to_float(float_ptr, fixed) \
    q_fixed_to_float(float_ptr, fixed, Q_FIXED_WF_12)
#define q7_fixed_to_float(float_ptr, fixed) \
    q_fixed_to_float(float_ptr, fixed, Q_FIXED_WF_7)

//
// fixed-point number addition
//
// argument:
// y        q_fixed object ptr
// x1       operand number1
// x2       operand number2
// is_sub   subtraction or not
static inline
void q_fixed_add(
    q_fixed *y, 
    q_fixed x1, q_fixed x2,
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

    *y = n1 + n2;
}
#define q15_fixed_add(q_fixed_ptr, x1, x2) \
    q_fixed_add(q_fixed_ptr, x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_add(q_fixed_ptr, x1, x2) \
    q_fixed_add(q_fixed_ptr, x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_add(q_fixed_ptr, x1, x2) \
    q_fixed_add(q_fixed_ptr, x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_add(q_fixed_ptr, x1, x2) \
    q_fixed_add(q_fixed_ptr, x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)


//
// fixed-point number subtraction
//
// argument:
// y        q_fixed object ptr
// x1       operand number1
// x2       operand number2
static inline
void q_fixed_sub(
    q_fixed *y, 
    q_fixed x1, q_fixed x2,
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
#define q15_fixed_sub(q_fixed_ptr, x1, x2) \
    q_fixed_sub(q_fixed_ptr, x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_sub(q_fixed_ptr, x1, x2) \
    q_fixed_sub(q_fixed_ptr, x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_sub(q_fixed_ptr, x1, x2) \
    q_fixed_sub(q_fixed_ptr, x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_sub(q_fixed_ptr, x1, x2) \
    q_fixed_sub(q_fixed_ptr, x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number multiplication
//
// argument:
// y            q_fixed object ptr
// x1           operand number1
// x2           operand number2
static inline
void q_fixed_mul(
    q_fixed *y,
    q_fixed x1, q_fixed x2)
{
    *y = x1 * x2;
}
#define q15_fixed_mul_q30(q_fixed_ptr, x1, x2) \
    q_fixed_mul(q_fixed_ptr, x1, x2)
#define q14_fixed_mul_q28(q_fixed_ptr, x1, x2) \
    q_fixed_mul(q_fixed_ptr, x1, x2)
#define q12_fixed_mul_q24(q_fixed_ptr, x1, x2) \
    q_fixed_mul(q_fixed_ptr, x1, x2)
#define q7_fixed_mul_q14(q_fixed_ptr, x1, x2) \
    q_fixed_mul(q_fixed_ptr, x1, x2)

// //
// // fixed-point number division
// //
// // argument:
// // y            result
// // x1           operand number1
// // x2           operand number2
// static inline
// void q_fixed_div(
//     q_fixed *y,
//     q_fixed x1, q_fixed x2)
// {

// }


//
// fixed-point number greater than comparison
//
// argument:
// x1           operand number1
// x2           operand number2
static inline
bool q_fixed_gt(
    q_fixed x1, q_fixed x2,
    int x1_wf, int x2_wf)
{
    q_fixed y;

    // i'm too smart
    q_fixed_sub(&y, x1, x2, x1_wf, x2_wf);
    
    if (y > 0)
        return true;
    return false;
}
#define q15_fixed_gt(x1, x2) \
    q_fixed_gt(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_gt(x1, x2) \
    q_fixed_gt(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_gt(x1, x2) \
    q_fixed_gt(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_gt(x1, x2) \
    q_fixed_gt(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number greater than comparison with equal
//
// argument:
// x1           operand number1
// x2           operand number2
static inline
bool q_fixed_gte(
    q_fixed x1, q_fixed x2,
    int x1_wf, int x2_wf)
{
    q_fixed y;

    // i'm too smart
    q_fixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y >= 0)
        return true;
    return false;
}
#define q15_fixed_gte(x1, x2) \
    q_fixed_gte(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_gte(x1, x2) \
    q_fixed_gte(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_gte(x1, x2) \
    q_fixed_gte(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_gte(x1, x2) \
    q_fixed_gte(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number less than comparison
//
// argument:
// x1           operand number1
// x2           operand number2
static inline
bool q_fixed_lt(
    q_fixed x1, q_fixed x2,
    int x1_wf, int x2_wf)
{
    q_fixed y;

    q_fixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y < 0)
        return true;
    return false;
}
#define q15_fixed_lt(x1, x2) \
    q_fixed_lt(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_lt(x1, x2) \
    q_fixed_lt(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_lt(x1, x2) \
    q_fixed_lt(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_lt(x1, x2) \
    q_fixed_lt(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number less than comparison with equal
//
// argument:
// x1           operand number1
// x2           operand number2
static inline
bool q_fixed_lte(
    q_fixed x1, q_fixed x2,
    int x1_wf, int x2_wf)
{
    q_fixed y;

    q_fixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y <= 0)
        return true;
    return false;
}
#define q15_fixed_lte(x1, x2) \
    q_fixed_lte(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_lte(x1, x2) \
    q_fixed_lte(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_lte(x1, x2) \
    q_fixed_lte(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_lte(x1, x2) \
    q_fixed_lte(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number equal comparison
//
// argument:
// x1           operand number1
// x2           operand number2
static inline
bool q_fixed_eq(
    q_fixed x1, q_fixed x2,
    int x1_wf, int x2_wf)
{
    q_fixed y;

    q_fixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y == 0)
        return true;
    return false;
}
#define q15_fixed_eq(x1, x2) \
    q_fixed_eq(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_eq(x1, x2) \
    q_fixed_eq(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_eq(x1, x2) \
    q_fixed_eq(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_eq(x1, x2) \
    q_fixed_eq(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number not equal comparison
//
// argument:
// x1           operand number1
// x2           operand number2
static inline
bool q_fixed_ne(
    q_fixed x1, q_fixed x2,
    int x1_wf, int x2_wf)
{
    q_fixed y;

    q_fixed_sub(&y, x1, x2, x1_wf, x2_wf);

    if (y != 0)
        return true;
    return false;
}
#define q15_fixed_ne(x1, x2) \
    q_fixed_ne(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)
#define q14_fixed_ne(x1, x2) \
    q_fixed_ne(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)
#define q12_fixed_ne(x1, x2) \
    q_fixed_ne(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)
#define q7_fixed_ne(x1, x2) \
    q_fixed_ne(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// symbolic function
//
static inline
int q_fixed_math_sign(q_fixed x1)
{
    if (__q_fixed_is_neg(x1)) {
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
static inline
q_fixed q_fixed_math_abs(q_fixed x1)
{
    if (__q_fixed_is_neg(x1)) {
        return x1 * -1;
    } else {
        return x1;
    }
}

//
// sin and cos function
//
// TODO: to be optimized
static inline
void q_fixed_math_sin_cos(
    q_fixed *sin, q_fixed *cos,
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

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_COMMON_Q_FIXED_H