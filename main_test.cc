#include <common/types.h>
#include <common/qfixed.h>
#include <common/bit.h>
#include <motor_control/clarke.h>
#include <motor_control/common.h>
#include <motor_control/encoder.h>
#include <motor_control/park.h>
#include <motor_control/observer/kalman_filter.h>
#include <motor_control/pid_control.h>
#include <motor_control/svm.h>
#include <stdio.h>



int main(int argc, char const *argv[])
{
    qfixed x1, x2;

    x1 = q15(0.13125);
    x2 = q15(0.31541);
    
    printf("result: %.4f ", 
        q15_fixed_to_float(q15_fixed_add(x1, x2)));   // 0.4466
    return 0;
}
