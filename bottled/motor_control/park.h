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
#define park_direct_2p(q_ptr, d_ptr, alpha, beta, theta_deg)        \
do {                                                                \
    const float __pi180 = M_PI / 180;                               \
    float __x0, __x1;                                               \
    __x0 = alpha * cos(theta_deg * __pi180);                        \
    __x1 = beta * sin(theta_deg * __pi180);                         \
    *d_ptr = __x0 + __x1;                                           \
    __x0 = -alpha * sin(theta_deg * __pi180);                       \
    __x1 = beta * cos(theta_deg * __pi180);                         \
    *q_ptr = __x0 + __x1;                                           \
} while(0)

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
#define park_inverse_2p(alpha_ptr, beta_ptr, q, d, theta_deg)       \
do {                                                                \
    const float __pi180 = M_PI / 180;                               \
    float __x0, __x1;                                               \
    __x0 = d * cos(theta_deg * __pi180);                            \
    __x1 = q * sin(theta_deg * __pi180);                            \
    *alpha_ptr = __x0 - __x1;                                       \
    __x0 = d * sin(theta_deg * __pi180);                            \
    __x1 = q * cos(theta_deg * __pi180);                            \
    *beta_ptr = __x0 + __x1;                                        \
} while(0)
// static inline
// void park_inverse_2p_float(alpha_beta *ab, q_d qd, int theta_deg)
// {

// }

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_PARK_H