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
void clarke_direct_3p_q15_fixed(alpha_beta *ab, phase_i v)
{
    float x0, x1;
    const int32_t sqrt3 = Q15_FIXED_SQRT3; // q15
    
    ab->alpha = v.ia;
    x0 = (sqrt3 * v.ia) / 3;
    x1 = (2 * sqrt3 * v.ib) / 3;
    ab->beta = x0 + x1;
}

//
// clarke inverse transform
//
static inline
void clarke_inverse_2p_q15_fixed(phase_i *v, alpha_beta ab)
{
    const int32_t sqrt3 = Q15_FIXED_SQRT3; // q15

    v->ia = ab.alpha;
    v->ib = (0 - ab.alpha + sqrt3 * ab.beta) / 2;
    v->ic = (0 - ab.alpha - sqrt3 * ab.beta) / 2;
}

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_CLARKE_H