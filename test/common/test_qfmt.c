#include <common/qfmt.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    qfmt x1, x2, tmp;
    float x1_f, x2_f;
    qfmt sin, cos;
    x1_f = 1.537;
    x2_f = 0.4;

    // Q31
    x1 = q15(0.3145);
    x2 = q15(0.5165);
    puts("====================q31======================");
    printf("q31: %d \t %d\n", x1, x2);
    tmp = q15_fmt_add(x1, x2);
    printf("q31: %d \t %f\n", tmp, ((27229) / (536870912)));

    return 0;
}
