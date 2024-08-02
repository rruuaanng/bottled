#ifndef NONGFU_SPRING_MOTOR_CONTROL_PARK_H
#define NONGFU_SPRING_MOTOR_CONTROL_PARK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <motor_control/common.h>

//
// park transform
//
static inline
void park_direct_2p_q15_fixed(
    q_d *qd, alpha_beta ab, int theta_deg)
{
    q_fixed sin_theta, cos_theta;

    q_fixed_math_sin_cos(&sin_theta, &cos_theta, theta_deg);
    qd->d = (ab.alpha * cos_theta) + (ab.beta * sin_theta);
    qd->q = (0 - ab.alpha * sin_theta) + (ab.beta * cos_theta);
}

//
// park inverse transform
//
static inline
void park_inverse_2p_q15_fixed(
    alpha_beta *ab, q_d qd, int theta_deg)
{
    q_fixed sin_theta, cos_theta;

    q_fixed_math_sin_cos(&sin_theta, &cos_theta, theta_deg);
    ab->alpha = (qd.d * cos_theta) - (qd.q * sin_theta);
    ab->beta = (qd.d * sin_theta) + (qd.q * cos_theta);
}

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_PARK_H