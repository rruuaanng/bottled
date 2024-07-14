#ifndef NONGFU_SPRING_MOTOR_CONTROL_OBSERVER_KALMAN_FILTER_H
#define NONGFU_SPRING_MOTOR_CONTROL_OBSERVER_KALMAN_FILTER_H

#include <common.h>

//
// kalman filter
//
void kalman_filter_q_fixed(
    int32_t *out,
    int32_t *x_last, int32_t *p_last,
    int32_t last_out, int32_t q, int32_t r)
{
    int32_t x_mid, x_now;
    int32_t p_mid, p_now;
    int32_t kg;

    x_mid = *x_last;
    p_mid = *p_last + q;
    kg = p_mid / (p_mid + r);
    x_now = x_mid + kg * (last_out - x_mid);
    p_now = (1 - kg) * p_mid;

    *p_last = p_now;
    *x_last = x_now;
    *out = x_now;
}

#endif // NONGFU_SPRING_MOTOR_CONTROL_OBSERVER_KALMAN_FILTER_H
