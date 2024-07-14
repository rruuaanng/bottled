#ifndef NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H
#define NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H

#include <common.h>

//
// PID control
//
void pid_control_q_fixed(
    int32_t *err_sum, int32_t *prev_err, 
    int32_t *out,
    int32_t kp, int32_t ki, int32_t kd,
    int32_t measured_val, int32_t target)
{
    int32_t err;
    err = target - measured_val;

    int32_t diff;
    diff = err - (*prev_err);
    
    int32_t p, i, d;
    p = kp * err;
    i = ki * (*err_sum);
    d = kd * diff;

    *prev_err = err;
    *err_sum += err;
    *out = (p + i + d);
}

#endif // NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H