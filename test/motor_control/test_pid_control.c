#include <stdio.h>
#include <motor_control/pid_control.h>


int main(int argc, char const *argv[])
{
    qfixed err_sum, prev_err;
    qfixed out;
    float p, i, d;

    // initialize
    p = 0.11;
    i = 1.3;
    d = 2.4;
    err_sum = 0; prev_err = 0;

    puts("=====*1*=====");
    pid_control_q15(&err_sum, &prev_err, &out, 
                p, i, d, 30, 35);
    printf("out: %.4f \n", q15_fixed_to_float(out));
    // err: 5       prev_err: 0  
    // diff: 5      err_sum: 0
    
    puts("=====*2*=====");
    pid_control_q15(&err_sum, &prev_err, &out, 
             p, i, d, 34, 35);
    printf("out: %.4f \n", q15_fixed_to_float(out));
    // err: 1       prev_err: 5
    // diff: -4     err_sum: 5

    puts("=====*3*=====");
    pid_control_q15(&err_sum, &prev_err, &out, 
             p, i, d, 35, 35);
    printf("out: %.4f \n", q15_fixed_to_float(out));
    // err: 0       prev_err: 1  
    // diff: -1     err_sum: 6
    
    return 0;
}
