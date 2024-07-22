#ifndef NFWATER_Q_FIXED_H
#define NFWATER_Q_FIXED_H

//
// import standard library
//
#include <stdint.h>
#include <stdbool.h>


#define max(x, y)                       ((x) > (y) ? (x): (y))

#define min(x, y)                       ((x) < (y) ? (x): (y))

#define diff(x, y)                      (max(x, y) - min(x, y))

#define __if_else(cond, s1, s2)         ((cond) ? (s1): (s2))

#define __to_q_fixed(n, wf)             (int32_t)((n) * (1 << (wf)))

#define __get_symbol_bit()              (1 << ((sizeof(int32_t) * 8) - 1))

#define q_fixed_is_neg(n)               ((n) & __get_symbol_bit()? 1: 0)

//
// q_fixed structure
//
typedef struct {
    int32_t N;
#define Q_FIXED_SIZE                    0x20 // 4byte
    int wf;
#define Q_FIXED_WF_31                   Q_FIXED_SIZE - 1    // Q31
#define Q_FIXED_WF_15                   0x0F                // Q15
#define Q_FIXED_WF_7                    0x07                // Q7
}q_fixed;

//
// define a q_fixed object
//
// argument:
// name     variable name
// fixed    fixed-point value
// wf       bit width
#define q_fixed(name, fixed, wf) \
    q_fixed name = {fixed, __if_else(wf <= Q_FIXED_SIZE, wf, Q_FIXED_SIZE)}

#define q31_fixed(name, fixed) \
    q_fixed name = {fixed, Q_FIXED_WF_31}

#define q15_fixed(name, fixed) \
    q_fixed name = {fixed, Q_FIXED_WF_15}

#define q7_fixed(name, fixed) \
    q_fixed name = {fixed, Q_FIXED_WF_7}

#define q_fixed_float(name, n, wf) \
    q_fixed name = {__to_q_fixed(n, wf), wf}

#define q31_fixed_float(name, n) \
    q_fixed name = {__to_q_fixed(n, Q_FIXED_WF_31), Q_FIXED_WF_31}

#define q15_fixed_float(name, n) \
    q_fixed name = {__to_q_fixed(n, Q_FIXED_WF_15), Q_FIXED_WF_15}

#define q7_fixed_float(name, n) \
    q_fixed name = {__to_q_fixed(n, Q_FIXED_WF_7), Q_FIXED_WF_7}

//
// define a q_fixed constant
//
#define Q_FIXED_VAL(fixed, wf) \
    {fixed, __if_else(wf <= Q_FIXED_SIZE, wf, Q_FIXED_SIZE)}

#define Q_FIXED_FVAL(n, wf) \
    __to_q_fixed(n, __if_else(wf <= Q_FIXED_SIZE, wf, Q_FIXED_SIZE));

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

    fixed->N = __to_q_fixed(n, wf);
    fixed->wf = wf;
}

//
// fixed-point number convert to float-point number
//
// argument:
// n        float-point number ptr
// fixed    q_fixed object
static inline
int q_fixed_to_float(float *n, q_fixed fixed)
{
    uint16_t offset;
    uint32_t tmp;
    uint32_t in_fixed;

    offset = 0x3f80 + ((31 - fixed.wf) * ((uint32_t)(1) << (23 - 16)));

    if (fixed.wf > Q_FIXED_SIZE)
        fixed.wf = Q_FIXED_SIZE;

    if (fixed.N < 0) {
        offset |= 0x8000;
        in_fixed = -fixed.N;
    } else if (fixed.N == 0) {
        return 1;
    } else {
        in_fixed = fixed.N;
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
    bool is_sub)
{
    int32_t n1, n2;
    int wf_diff;

    n1 = x1.N;
    n2 = x2.N;
    
    // align decimal places
    wf_diff = diff(x1.wf, x2.wf);
    __if_else(x1.wf < x2.wf, 
              n1 <<= wf_diff,
              n2 <<= wf_diff);

    __if_else(is_sub,
              y->N = n1 - n2,
              y->N = n1 + n2);

    // update the wf of the result
    y->wf = max(x1.wf, x2.wf);
}

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
    int lim;

    lim = x1.wf + x2.wf;

    y->N = x1.N * x2.N;
    __if_else(lim < (Q_FIXED_SIZE * 2),
              y->wf = lim,
              y->wf = (Q_FIXED_SIZE * 2));
}

//
// fixed-point number constant multiplication
//
// argument:
// y            q_fixed object ptr
// x1           operand number1
// x2           operand number2
static inline
void q_fixed_mul_const(
    q_fixed *y,
    q_fixed x1, int x2)
{
    y->N = x1.N * x2;
    y->wf = max(x1.wf, x1.wf);
}

//
// fixed-point number division
//
// argument:
// y            result
// x1           operand number1
// x2           operand number2
static inline
void q_fixed_div(
    q_fixed *y,
    q_fixed x1, q_fixed x2)
{

}

//
// fixed-point number constant division
//
// argument:
// y            result
// x1           operand number1
// x2           operand number2
static inline
void q_fixed_div_const(
    q_fixed *y,
    q_fixed x1, int x2)
{
    y->N = x1.N / x2;
    y->wf = max(x1.wf, x1.wf);
}

//
// fixed-point number greater than comparison
//
// argument:
// x1           operand number1
// x2           operand number2
// is_with_eq   whether to include equal to
static inline
bool q_fixed_gt(q_fixed x1, q_fixed x2, bool is_with_eq)
{
    q_fixed y;
    bool a;

    // i'm too smart
    q_fixed_add(&y, x1, x2, true);
    __if_else(is_with_eq,{
        a = __if_else(y.N >= 0, true, false);
    },{
        a = __if_else(y.N > 0, true, false);
    });

    return a;
}

//
// fixed-point number less than comparison
//
// argument:
// x1           operand number1
// x2           operand number2
// is_with_eq   whether to include equal to
static inline
bool q_fixed_lt(q_fixed x1, q_fixed x2, bool is_with_eq)
{
    q_fixed y;
    bool a;

    q_fixed_add(&y, x1, x2, true);
    __if_else(is_with_eq,{
        a = __if_else(y.N <= 0, true, false);
    },{
        a = __if_else(y.N < 0, true, false);
    });

    return a;
}

//
// fixed-point number equal comparison
//
// argument:
// x1           operand number1
// x2           operand number2
// is_ne        isn't equal to
static inline
bool q_fixed_eq(q_fixed x1, q_fixed x2, bool is_ne)
{
    q_fixed y;
    bool a;

    q_fixed_add(&y, x1, x2, true);
    __if_else(is_ne,{
        a = __if_else(y.N != 0, true, false);
    },{
        a = __if_else(y.N == 0, true, false);
    });
    
    return a;
}

//
// symbolic function
//
int q_fixed_math_sign(q_fixed x1)
{
    if (q_fixed_is_neg(x1.N)) {
        return -1;
    } else if (x1.N != 0){
        return 1;
    } else {
        return 0;
    }
}

//
// absolute value function
//
int32_t q_fixed_math_abs(q_fixed x1)
{
    if (q_fixed_is_neg(x1.N)) {
        return x1.N * -1;
    } else {
        return x1.N;
    }
}

#endif // NFWATER_Q_FIXED_H