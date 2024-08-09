#include <stdio.h>
#include <motor_control/observer/kalman_filter.h>


int main(int argc, char const *argv[])
{
    int32_t out;
    int32_t x_last, p_last;
    
    x_last = q15(1); p_last = q15(2);

    puts("======*1*======");
    kalman_filter_q15(&out, &x_last, &p_last, 30, 1, 1);
    printf("%.4f \n", q15_fixed_to_float(out));

    puts("======*2*======");
    kalman_filter_q15(&out, &x_last, &p_last, 33, 0.2, 1);

    printf("%.4f \n", q15_fixed_to_float(out));
    return 0;
}
