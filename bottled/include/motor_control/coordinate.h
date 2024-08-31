#ifndef NONGFU_SPRING_MOTOR_CONTROL_COORDINATE_H
#define NONGFU_SPRING_MOTOR_CONTROL_COORDINATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <motor_control/common.h>

void clarke_direct_3p_q15(alpha_beta *, phase_i);
void clarke_inverse_2p_q15(phase_i *, alpha_beta);
void park_direct_2p_q15(q_d *, alpha_beta, int);
void park_inverse_2p_q15(alpha_beta *, q_d, int);

#define clarke_direct_3p(alpha_ptr, beta_ptr, ia, ib)       \
do {                                                        \
    float __x0, __x1;                                       \
    const float __sqrt3 = 1.73205f;                         \
    *alpha_ptr = ia;                                        \
    __x0 = (__sqrt3 * ia) / 3;                              \
    __x1 = (2 * __sqrt3 * ib) / 3;                          \
    *beta_ptr = __x0 + __x1;                                \
} while(0)

#define clarke_inverse_2p(ia_ptr, ib_ptr, ic_ptr, alpha, beta)       \
do {                                                                 \
    const float sqrt3 = 1.73205f;                                    \
    *ia_ptr = alpha;                                                 \
    *ib_ptr = (0 - alpha + sqrt3 * beta) / 2;                        \
    *ic_ptr = (0 - alpha - sqrt3 * beta) / 2;                        \
} while(0)

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

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_COORDINATE_H