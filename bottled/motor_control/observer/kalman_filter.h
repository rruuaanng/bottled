#ifndef NONGFU_SPRING_MOTOR_CONTROL_OBSERVER_KALMAN_FILTER_H
#define NONGFU_SPRING_MOTOR_CONTROL_OBSERVER_KALMAN_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <motor_control/common.h>

//
// kalman filter
//
static inline
void kalman_filter(
    int32_t *out,
    int32_t *x_last, int32_t *p_last,
    int32_t measured_val, int32_t q, int32_t r)
{
    int32_t x_mid, x_now;
    int32_t p_mid, p_now;
    int32_t kg;

    x_mid = *x_last;
    p_mid = *p_last + q;
    kg = p_mid / (p_mid + r);
    x_now = x_mid + kg * (measured_val - x_mid);
    p_now = (1 - kg) * p_mid;

    *p_last = p_now;
    *x_last = x_now;
    *out = x_now;
}

#ifdef __cplusplus
}
#endif

#endif // NONGFU_SPRING_MOTOR_CONTROL_OBSERVER_KALMAN_FILTER_H
