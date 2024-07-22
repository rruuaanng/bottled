#ifndef NONGFU_SPRING_MOTOR_CONTROL_PARK_H
#define NONGFU_SPRING_MOTOR_CONTROL_PARK_H

#include <motor_control/common.h>

//
// park transform
//
void park_direct_2p_q_fixed(
    q_d *qd, alpha_beta ab,
    int32_t sin_theta, int32_t cos_theta)
{

}

//
// park inverse transform
//
void park_inverse_2p_q_fixed(
    alpha_beta *ab, q_d qd,
    int32_t sin_theta, int32_t cos_theta)
{
    
}

#endif // NONGFU_SPRING_MOTOR_CONTROL_PARK_H