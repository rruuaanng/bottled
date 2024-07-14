#ifndef NONGFU_SPRING_MOTOR_CONTROL_CLARKE_H
#define NONGFU_SPRING_MOTOR_CONTROL_CLARKE_H

#include <common.h>

// 
// clarke transform
//
void clarke_direct_3p_q_fixed(alpha_beta *ab, phase_v v)
{
    float x0, x1;
    const int32_t sqrt3 = 56756; // q15
    
    ab->alpha = v.A;
    x0 = (sqrt3 * v.A) / 3;
    x1 = (2 * sqrt3 * v.B) / 3;
    ab->beta = x0 + x1;
}

//
// clarke inverse transform
//
static inline
void clarke_inverse_2p_q_fixed(phase_v *v, alpha_beta ab)
{
    const int32_t sqrt3 = 56756; // q15

    v->A = ab.alpha;
    v->B = (0 - ab.alpha + sqrt3 * ab.beta) / 2;
    v->C = (0 - ab.alpha - sqrt3 * ab.beta) / 2;
}

#endif // NONGFU_SPRING_MOTOR_CONTROL_CLARKE_H