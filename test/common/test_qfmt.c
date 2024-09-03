#include <common/qfmt.h>
#include <stdio.h>


#define TEST_Q_BLOCK(num)                                            \
do{                                                                  \
    qfmt x1, x2, tmp;                                                \
    x1 = q##num(0.3145);                                             \
    x2 = q##num(0.5165);                                             \
    printf("==================Q%d=====================\n", num);     \
    printf("q%d: %d \t %d\n", num, x1, x2);                          \
    tmp = qfmt_add(x1, x2);                                          \
    printf("add: %d \t %f\n", tmp, q##num##_fmt_to_float(tmp));      \
    tmp = qfmt_sub(x1, x2);                                          \
    printf("sub: %d \t %f\n", tmp, q##num##_fmt_to_float(tmp));      \
    tmp = q##num##_fmt_mul(x1, x2);                                  \
    printf("mul: %d \t %f\n", tmp, q##num##_fmt_to_float(tmp));      \
    tmp = q##num##_fmt_div(x1, x2);                                  \
    printf("div: %d \t %f\n", tmp, q##num##_fmt_to_float(tmp));      \
} while(0)

int main(int argc, char const *argv[])
{
    qfmt sin, cos;

    // testing
    TEST_Q_BLOCK(30);
    TEST_Q_BLOCK(29);
    TEST_Q_BLOCK(28);
    TEST_Q_BLOCK(27);
    TEST_Q_BLOCK(26);
    TEST_Q_BLOCK(25);
    TEST_Q_BLOCK(24);
    TEST_Q_BLOCK(23);
    TEST_Q_BLOCK(22);
    TEST_Q_BLOCK(21);
    TEST_Q_BLOCK(20);
    TEST_Q_BLOCK(19);
    TEST_Q_BLOCK(18);
    TEST_Q_BLOCK(17);
    TEST_Q_BLOCK(16);
    TEST_Q_BLOCK(15);
    TEST_Q_BLOCK(14);
    TEST_Q_BLOCK(13);
    TEST_Q_BLOCK(12);
    TEST_Q_BLOCK(11);
    TEST_Q_BLOCK(10);
    TEST_Q_BLOCK(9);
    TEST_Q_BLOCK(8);
    TEST_Q_BLOCK(7);

    return 0;
}
