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
void park_direct_2p_q15(q_d *qd, alpha_beta ab, int theta_deg)
{
    qfixed x0, x1;
    qfixed sin_theta, cos_theta;

    qfixed_math_sin_cos_q15(&sin_theta, &cos_theta, theta_deg);

    x0 = q15_fixed_mul(ab.alpha, cos_theta);
    x1 = q15_fixed_mul(ab.beta, sin_theta);
    qd->d = q15_fixed_add(x0, x1);
    
    x0 = q15_fixed_mul(-ab.alpha, sin_theta);
    x1 = q15_fixed_mul(ab.beta, cos_theta);
    qd->q = q15_fixed_add(x0, x1);
}
static inline
void park_direct_2p_float(q_d *qd, alpha_beta ab, int theta_deg)
{
    const float pi180 = M_PI / 180;
    float x0, x1;

    x0 = ab.alpha_float * cos(theta_deg * pi180);
    x1 = ab.beta_float * sin(theta_deg * pi180);
    qd->d_float = x0 + x1;

    x0 = -ab.alpha_float * sin(theta_deg * pi180);
    x1 = ab.beta_float * cos(theta_deg * pi180);
    qd->q_float = x0 + x1;
}

//
// park inverse transform
//
static inline
void park_inverse_2p_q15(alpha_beta *ab, q_d qd, int theta_deg)
{
    qfixed x0, x1;
    qfixed sin_theta, cos_theta;

    qfixed_math_sin_cos_q15(&sin_theta, &cos_theta, theta_deg);
    x0 = q15_fixed_mul(qd.d, cos_theta);
    x1 = q15_fixed_mul(qd.q, sin_theta);
    ab->alpha = q15_fixed_sub(x0, x1);
    
    x0 = q15_fixed_mul(qd.d, sin_theta);
    x1 = q15_fixed_mul(qd.q, cos_theta);
    ab->beta = q15_fixed_add(x0, x1);
}
static inline
void park_inverse_2p_float(alpha_beta *ab, q_d qd, int theta_deg)
{
    const float pi180 = M_PI / 180; 
    float x0, x1;

    x0 = qd.d_float * cos(theta_deg * pi180);
    x1 = qd.q_float * sin(theta_deg * pi180);
    ab->alpha_float = x0 - x1;

    x0 = qd.d_float * sin(theta_deg * pi180);
    x1 = qd.q_float * cos(theta_deg * pi180);
    ab->beta_float = x0 + x1;
}

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_PARK_H