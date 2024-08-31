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
void kalman_filter_q15(
    int32_t *out,
    int32_t *x_last_q15, int32_t *p_last_q15,
    int32_t measured_val, float q, float r)
{
    int32_t x_mid, x_now;
    int32_t p_mid, p_now;
    int32_t kg;

    x_mid = *x_last_q15;
    p_mid = *p_last_q15 + q15(q);

    kg = q15_fmt_div(p_mid, q15_fmt_add(p_mid, q15(r)));
    x_now = q15_fmt_mul(
        q15_fmt_add(x_mid, kg),
        q15_fmt_sub(q15(measured_val), x_mid));
    p_now = q15_fmt_mul(q15_fmt_sub(q15(1), kg), p_mid);

    *p_last_q15 = p_now;
    *x_last_q15 = x_now;
    *out = x_now;
}

#ifdef __cplusplus
}
#endif

#endif // NONGFU_SPRING_MOTOR_CONTROL_OBSERVER_KALMAN_FILTER_H
