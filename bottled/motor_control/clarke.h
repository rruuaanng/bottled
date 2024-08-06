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
void clarke_direct_3p(alpha_beta *ab, phase_i i)
{
    float x0, x1;
    const q_fixed sqrt3 = Q15_FIXED_SQRT3; // q15
    
    ab->alpha = i.ia;
    x0 = (sqrt3 * i.ia) / 3;
    x1 = (2 * sqrt3 * i.ib) / 3;
    ab->beta = x0 + x1;
}

//
// clarke inverse transform
//
static inline
void clarke_inverse_2p(phase_i *i, alpha_beta ab)
{
    const q_fixed sqrt3 = Q15_FIXED_SQRT3; // q15

    i->ia = ab.alpha;
    i->ib = (0 - ab.alpha + sqrt3 * ab.beta) / 2;
    i->ic = (0 - ab.alpha - sqrt3 * ab.beta) / 2;
}

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_CLARKE_H