#ifndef NONGFU_SPRING_MOTOR_CONTROL_CLARKE_H
#define NONGFU_SPRING_MOTOR_CONTROL_CLARKE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <motor_control/common.h>

// 
// clarke transform
//
// assuming three-phase balance, then A+B+C=0
// 1. alpha = Ia - 1/2Ib - 1/2Ic
// 2. due to B=C, then 1/2Ib - 1/2Ic = 0
// 3. alpha = Ia - 0
// 4. alpha = Ia
//
// 1. beta = 2/3 * (sqrt(3)/2Ib - sqrt(3)/2Ic)
// 2. A+B+C=0, then C=-A-B
// 3. beta = 2/3 * (sqrt(3)/2Ib + sqrt(3)/2IA + sqrt(3)/2Ib)
// 4. beta = 2/3 * (sqrt(3)/2Ia + sqrt(3)Ib)
// 5. beta = sqrt(3)/3Ia + 2sqrt(3)/3Ib
static inline
void clarke_direct_3p_q15(alpha_beta *ab, phase_i i)
{
    qfixed x0, x1;
    const qfixed sqrt3 = Q15_FIXED_SQRT3; // q15
    
    ab->alpha = i.ia;
    x0 = q15_fixed_mul(sqrt3, i.ia) / 3;
    x1 = q15_fixed_mul(2 * sqrt3, i.ib) / 3;
    ab->beta = x0 + x1;
}
#define clarke_direct_3p(alpha_ptr, beta_ptr, ia, ib)       \
do {                                                        \
    float __x0, __x1;                                       \
    const float __sqrt3 = 1.73205f;                         \
    *alpha_ptr = ia;                                        \
    __x0 = (__sqrt3 * ia) / 3;                              \
    __x1 = (2 * __sqrt3 * ib) / 3;                          \
    *beta_ptr = __x0 + __x1;                                \
} while(0)

//
// clarke inverse transform
//
static inline
void clarke_inverse_2p_q15(phase_i *i, alpha_beta ab)
{
    const qfixed sqrt3 = Q15_FIXED_SQRT3; // q15

    i->ia = ab.alpha;
    i->ib = q15_fixed_add(0 - ab.alpha, q15_fixed_mul(sqrt3, ab.beta)) / 2;
    i->ic = q15_fixed_sub(0 - ab.alpha, q15_fixed_mul(sqrt3, ab.beta)) / 2;
}
#define clarke_inverse_2p(ia_ptr, ib_ptr, ic_ptr, alpha, beta)       \
do {                                                                 \
    const float sqrt3 = 1.73205f;                                    \
    *ia_ptr = alpha;                                                 \
    *ib_ptr = (0 - alpha + sqrt3 * beta) / 2;                        \
    *ic_ptr = (0 - alpha - sqrt3 * beta) / 2;                        \
} while(0)

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_CLARKE_H