#ifndef NONGFU_SPRING_COMMON_QFMT_H
#define NONGFU_SPRING_COMMON_QFMT_H

#ifdef __cplusplus
extern "C" {
#endif

//
// import standard library
//
#include <stdint.h>
#include <stdbool.h>

//
// qfmt math constant
//
#define Q15_FMT_SQRT3                   0xDDB4

//
// table of sin and cos function value
//
// note:
//  type            q15_fixed
//  interval        [0, pi/2]
//  index           [0, 255) => [0, 254]
#define SIN_COS_TABLE_SIZE               0xFF
#define SIN_COS_TABLE   {                                    \
    0x0000,0x00C7,0x023A,0x023A,0x0322,0x0474,0x0474,0x057D, \
    0x06B1,0x06B1,0x07D8,0x08EB,0x08EB,0x0A33,0x0B26,0x0B26, \
    0x0C8B,0x0D60,0x0E1B,0x0F97,0x0F97,0x1072,0x11CE,0x11CE, \
    0x12C7,0x1404,0x1404,0x151B,0x1638,0x1638,0x176C,0x186C, \
    0x186C,0x19BD,0x1A9C,0x1B46,0x1CC9,0x1CC9,0x1D91,0x1EF6, \
    0x1EF6,0x1FDB,0x2120,0x2120,0x2223,0x2346,0x2346,0x2467, \
    0x256A,0x256A,0x26A7,0x278D,0x2827,0x29A9,0x29A9,0x2A61, \
    0x2BC6,0x2BC6,0x2C98,0x2DDC,0x2DDC,0x2ECB,0x2FF2,0x2FF2, \
    0x30FC,0x3202,0x3202,0x3326,0x340E,0x3495,0x3617,0x3617, \
    0x36BB,0x381A,0x381A,0x38D8,0x3A19,0x3A19,0x3AF1,0x3C15, \
    0x3C15,0x3D07,0x3E0D,0x3E0D,0x3F17,0x4000,0x4072,0x41EB, \
    0x41EB,0x4278,0x43D3,0x43D3,0x447A,0x45B5,0x45B5,0x4673, \
    0x4790,0x4790,0x4868,0x4968,0x4968,0x4A57,0x4B39,0x4B9F, \
    0x4D07,0x4D07,0x4D81,0x4ECB,0x4ECB,0x4F5F,0x508C,0x508C, \
    0x5134,0x5243,0x5243,0x5302,0x53F7,0x5432,0x54C9,0x55A5, \
    0x55F3,0x5748,0x5748,0x57B1,0x58E8,0x58E8,0x5965,0x5A82, \
    0x5A82,0x5B0F,0x5C12,0x5C28,0x5CB2,0x5D9B,0x5D9B,0x5E4F, \
    0x5F1D,0x5F5F,0x609A,0x609A,0x60EB,0x620C,0x620C,0x6271, \
    0x6378,0x6378,0x63ED,0x64DD,0x64DD,0x6563,0x6638,0x6638, \
    0x66CF,0x678D,0x67BE,0x68D8,0x68D8,0x6919,0x6A1C,0x6A1C, \
    0x6A6E,0x6B57,0x6B57,0x6BB9,0x6C8B,0x6C8B,0x6CF7,0x6DB5, \
    0x6DB5,0x6E2E,0x6ED9,0x6EF9,0x6FF2,0x6FF2,0x7024,0x7102, \
    0x7102,0x7141,0x720C,0x720C,0x7254,0x7308,0x7308,0x735D, \
    0x7401,0x7401,0x745D,0x74ED,0x7504,0x75D2,0x75D2,0x75F3, \
    0x76AB,0x76AB,0x76D9,0x777C,0x777C,0x77B4,0x7844,0x7844, \
    0x7883,0x7906,0x7906,0x794A,0x79BA,0x79C7,0x7A68,0x7A68, \
    0x7A7B,0x7B08,0x7B08,0x7B26,0x7BA2,0x7BA2,0x7BC3,0x7C2F, \
    0x7C2F,0x7C5A,0x7CB5,0x7CB5,0x7CE3,0x7D32,0x7D38,0x7DA5, \
    0x7DA5,0x7DAE,0x7E0D,0x7E0D,0x7E1E,0x7E69,0x7E69,0x7E80, \
    0x7EBE,0x7EBB,0x7ED5,0x7F0A,0x7F0A,0x7F21,0x7F4B,0x7F4B, \
    0x7F80,0x7F80,0x7F86,0x7FAE,0x7FAE,0x7FB4,0x7FD2,0x7FCE, \
    0x7FD8,0x7FE9,0x7FE9,0x7FEF,0x7FF9,0x7FF9,0x7FFC,0x8000}
#define DIV_NUM_TABLE   {                           \
    0x7F, 0x7D, 0x7B, 0x79, 0x78, 0x76, 0x74, 0x73, \
    0x71, 0x6F, 0x6E, 0x6D, 0x6B, 0x6A, 0x68, 0x67, \
    0x66, 0x65, 0x63, 0x62, 0x61, 0x60, 0x5F, 0x5E, \
    0x5D, 0x5C, 0x5B, 0x5A, 0x59, 0x58, 0x57, 0x56, \
    0x55, 0x54, 0x53, 0x52, 0x52, 0x51, 0x50, 0x4F, \
    0x4E, 0x4E, 0x4D, 0x4C, 0x4C, 0x4B, 0x4A, 0x49, \
    0x49, 0x48, 0x48, 0x47, 0x46, 0x46, 0x45, 0x45, \
    0x44, 0x43, 0x43, 0x42, 0x42, 0x41, 0x41, 0x40, \
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

//
// utils
//
#define max(x, y)                       ((x) > (y) ? (x): (y))
#define min(x, y)                       ((x) < (y) ? (x): (y))
#define diff(x, y)                      (max(x, y) - min(x, y))
#define __get_symbol_bit()              (1 << ((sizeof(int32_t) * 8) - 1))
#define __qfmt_is_neg(n)                ((n) & __get_symbol_bit()? 1: 0)
#define __to_qfmt(n, wf)                (int32_t)((n) * (1 << (wf)))
#define __to_float(fixed, wf)           (float)((fixed) / (1 << (wf)))
//
// qfmt structure
//
#define Q_FIXED_SIZE                    0x20                //
#define Q_FIXED_WF_30                   0x1E                //
#define Q_FIXED_WF_29                   0x1D                //
#define Q_FIXED_WF_28                   0x1C                //
#define Q_FIXED_WF_27                   0x1B                //
#define Q_FIXED_WF_26                   0x1A                //
#define Q_FIXED_WF_25                   0x19                //
#define Q_FIXED_WF_24                   0x18                //  
#define Q_FIXED_WF_23                   0x17                //
#define Q_FIXED_WF_22                   0x16                //
#define Q_FIXED_WF_21                   0x15                //
#define Q_FIXED_WF_20                   0x14                //
#define Q_FIXED_WF_19                   0x13                //
#define Q_FIXED_WF_18                   0x12                //
#define Q_FIXED_WF_17                   0x11                //
#define Q_FIXED_WF_16                   0x10                //
#define Q_FIXED_WF_15                   0x0F                //
#define Q_FIXED_WF_14                   0x0E                //
#define Q_FIXED_WF_13                   0x0D                //
#define Q_FIXED_WF_12                   0x0C                //
#define Q_FIXED_WF_11                   0x0B                //
#define Q_FIXED_WF_10                   0x0A                //
#define Q_FIXED_WF_9                    0x09                //
#define Q_FIXED_WF_8                    0x08                //
#define Q_FIXED_WF_7                    0x07                //
typedef int64_t                         qfmt;

#define qfmt_var(name, fixed) \
    qfmt name = fixed
#define qfmt_fvar(name, n_float, wf) \
    qfmt name = __to_qfmt(n_float, wf)

//
// fast convert to qfmt
//
#define qxx(n_float, wf)                __to_qfmt(n_float, wf)
#define q30(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_30)
#define q29(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_29)
#define q28(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_28)
#define q27(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_27)
#define q26(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_26)
#define q25(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_25)
#define q24(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_24)
#define q23(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_23)
#define q22(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_22)
#define q21(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_21)
#define q20(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_20)
#define q19(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_19)
#define q18(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_18)
#define q17(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_17)
#define q16(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_16)
#define q15(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_15)
#define q14(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_14)
#define q13(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_13)
#define q12(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_12)
#define q11(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_11)
#define q10(n_float)                    __to_qfmt(n_float, Q_FIXED_WF_10)
#define q9(n_float)                     __to_qfmt(n_float, Q_FIXED_WF_9)
#define q8(n_float)                     __to_qfmt(n_float, Q_FIXED_WF_8)
#define q7(n_float)                     __to_qfmt(n_float, Q_FIXED_WF_7)

//
// qfmt multiplying and dividing multiples of two
//
#define qfmt_mul2(fixed)             ((fixed) << (1))
#define qfmt_mul4(fixed)             ((fixed) << (2))
#define qfmt_mul8(fixed)             ((fixed) << (3))
#define qfmt_mul16(fixed)            ((fixed) << (4))
#define qfmt_mul32(fixed)            ((fixed) << (5))
#define qfmt_mul64(fixed)            ((fixed) << (6))

#define qfmt_div2(fixed)             ((fixed) >> (1))
#define qfmt_div4(fixed)             ((fixed) >> (2))
#define qfmt_div8(fixed)             ((fixed) >> (3))
#define qfmt_div16(fixed)            ((fixed) >> (4))
#define qfmt_div32(fixed)            ((fixed) >> (5))
#define qfmt_div64(fixed)            ((fixed) >> (6))

//
// float-point number convert to fixed-point number
//
extern qfmt float_to_qfmt(float, int);
#define float_to_q30_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_30)

#define float_to_q29_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_29)

#define float_to_q28_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_28)

#define float_to_q27_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_27)

#define float_to_q26_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_26)

#define float_to_q25_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_25)

#define float_to_q24_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_24)

#define float_to_q23_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_23)

#define float_to_q22_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_22)

#define float_to_q21_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_21)

#define float_to_q20_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_20)

#define float_to_q19_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_19)

#define float_to_q18_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_18)

#define float_to_q17_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_17)

#define float_to_q16_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_16)

#define float_to_q15_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_15)

#define float_to_q14_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_14)

#define float_to_q13_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_13)

#define float_to_q12_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_12)

#define float_to_q11_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_11)

#define float_to_q10_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_10)

#define float_to_q9_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_9)

#define float_to_q8_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_8)

#define float_to_q7_fmt(n_float) \
    float_to_qfmt(n_float, Q_FIXED_WF_7)
    
//
// fixed-point number convert to float-point number
//
extern float qfmt_to_float(qfmt, int);
#define q30_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_30)

#define q29_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_29)

#define q28_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_28)

#define q27_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_27)

#define q26_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_26)

#define q25_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_25)

#define q24_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_24)

#define q23_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_23)

#define q22_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_22)

#define q21_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_21)

#define q20_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_20)

#define q19_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_19)

#define q18_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_18)

#define q17_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_17)

#define q16_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_16)

#define q15_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_15)

#define q14_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_14)

#define q13_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_13)

#define q12_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_12)

#define q11_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_11)

#define q10_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_10)

#define q9_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_9)

#define q8_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_8)

#define q7_fmt_to_float(fixed) \
    qfmt_to_float(fixed, Q_FIXED_WF_7)

//
// fixed-point number addition
//
extern qfmt qfmt_add(qfmt, qfmt, int, int);
#define q30_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_30, Q_FIXED_WF_30)

#define q29_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_29, Q_FIXED_WF_29)

#define q28_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_28, Q_FIXED_WF_28)

#define q27_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_27, Q_FIXED_WF_27)

#define q26_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_26, Q_FIXED_WF_26)

#define q25_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_25, Q_FIXED_WF_25)

#define q24_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_24, Q_FIXED_WF_24)

#define q23_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_23, Q_FIXED_WF_23)

#define q22_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_22, Q_FIXED_WF_22)

#define q21_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_21, Q_FIXED_WF_21)

#define q20_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_20, Q_FIXED_WF_20)

#define q19_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_19, Q_FIXED_WF_19)

#define q18_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_18, Q_FIXED_WF_18)

#define q17_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_17, Q_FIXED_WF_17)

#define q16_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_16, Q_FIXED_WF_16)

#define q15_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)

#define q14_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)

#define q13_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_13, Q_FIXED_WF_13)

#define q12_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)

#define q11_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_11, Q_FIXED_WF_11)

#define q10_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_10, Q_FIXED_WF_10)

#define q9_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_9, Q_FIXED_WF_9)

#define q8_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_8, Q_FIXED_WF_8)

#define q7_fmt_add(x1, x2) \
    qfmt_add(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number subtraction
//  
extern qfmt qfmt_sub(qfmt, qfmt, int, int);
#define q30_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_30, Q_FIXED_WF_30)

#define q29_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_29, Q_FIXED_WF_29)

#define q28_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_28, Q_FIXED_WF_28)

#define q27_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_27, Q_FIXED_WF_27)

#define q26_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_26, Q_FIXED_WF_26)

#define q25_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_25, Q_FIXED_WF_25)

#define q24_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_24, Q_FIXED_WF_24)

#define q23_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_23, Q_FIXED_WF_23)

#define q22_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_22, Q_FIXED_WF_22)

#define q21_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_21, Q_FIXED_WF_21)

#define q20_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_20, Q_FIXED_WF_20)

#define q19_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_19, Q_FIXED_WF_19)

#define q18_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_18, Q_FIXED_WF_18)

#define q17_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_17, Q_FIXED_WF_17)

#define q16_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_16, Q_FIXED_WF_16)

#define q15_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_15, Q_FIXED_WF_15)

#define q14_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_14, Q_FIXED_WF_14)

#define q13_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_13, Q_FIXED_WF_13)

#define q12_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_12, Q_FIXED_WF_12)

#define q11_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_11, Q_FIXED_WF_11)

#define q10_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_10, Q_FIXED_WF_10)

#define q9_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_9, Q_FIXED_WF_9)

#define q8_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_8, Q_FIXED_WF_8)

#define q7_fmt_sub(x1, x2) \
    qfmt_sub(x1, x2, Q_FIXED_WF_7, Q_FIXED_WF_7)

//
// fixed-point number multiplication
//
extern qfmt qfmt_mul(qfmt, qfmt, int);
#define q30_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_30)

#define q29_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_29)

#define q28_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_28)

#define q27_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_27)

#define q26_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_26)

#define q25_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_25)

#define q24_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_24)

#define q23_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_23)

#define q22_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_22)

#define q21_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_21)

#define q20_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_20)

#define q19_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_19)

#define q18_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_18)

#define q17_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_17)

#define q16_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_16)

#define q15_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_15)

#define q14_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_14)

#define q13_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_13)

#define q12_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_12)

#define q11_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_11)

#define q10_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_10)

#define q9_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_9)

#define q8_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_8)

#define q7_fmt_mul(x1, x2) \
    qfmt_mul(x1, x2, Q_FIXED_WF_7)

//
// fixed-point number division
//
extern qfmt qfmt_div(qfmt, qfmt, int);
#define q30_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_30)

#define q29_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_29)

#define q28_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_28)

#define q27_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_27)

#define q26_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_26)

#define q25_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_25)

#define q24_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_24)

#define q23_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_23)

#define q22_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_22)

#define q21_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_21)

#define q20_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_20)

#define q19_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_19)

#define q18_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_18)

#define q17_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_17)

#define q16_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_16)

#define q15_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_15)

#define q14_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_14)

#define q13_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_13)

#define q12_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_12)

#define q11_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_11)

#define q10_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_10)

#define q9_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_9)

#define q8_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_8)

#define q7_fmt_div(x1, x2) \
    qfmt_div(x1, x2, Q_FIXED_WF_7)

//
// math library
//
extern int qfmt_math_sign(qfmt);
extern qfmt qfmt_math_abs(qfmt);
extern void qfmt_math_sin_cos_q15(qfmt *, qfmt *, int);

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_COMMON_QFMT_H