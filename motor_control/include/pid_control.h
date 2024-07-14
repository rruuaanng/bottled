#ifndef NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H
#define NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H

#include <common.h>

//
// PID control
//
void pid_control(
    uint32_t *err_sum, uint32_t *prev_err, 
    float *out,
    float kp, float ki, float kd,
    uint32_t measured_val, uint32_t target)
{
    uint32_t err;
    err = target - measured_val;

    uint32_t diff;
    diff = err - (*prev_err);
    
    float p, i, d;
    p = kp * err;
    i = ki * (*err_sum);
    d = kd * diff;

    *prev_err = err;
    *err_sum += err;
    *out = (p + i + d);
}

#endif // NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H