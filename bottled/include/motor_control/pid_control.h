#ifndef NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H
#define NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <motor_control/common.h>

//
// PID control
//
static inline
void pid_control_q15(
    int32_t *err_sum, int32_t *prev_err, 
    int32_t *out,
    float kp, float ki, float kd,
    int32_t measured_val, int32_t target)
{
    int32_t err;
    int32_t diff;
    int32_t p, i, d;
    
    err = target - measured_val;
    diff = err - (*prev_err); 

    p = q15(kp) * err;
    i = q15(ki) * (*err_sum);
    d = q15(kd) * diff; 
    
    *prev_err = err;
    *err_sum += err;
    *out = q15_fixed_add(q15_fixed_add(p, i), d);
}

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_PID_CONTROL_H