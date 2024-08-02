#include <stdio.h>
#include <common/bit.h>


int main(int argc, char const *argv[])
{
    int n;

    // binary
    //  1101 1000
    n = 216;

    printf("TST (3): %d TST (5): %d\n", TST(n, 3), TST(n, 5));
    SET(n, 2); // 4
    SET(n, 0); // 1
    printf("SET (2): %d BIT (2): %d\n", n, TST(n, 2));
    CLR(n, 0); // 1
    printf("CLR (0): %d BIT (0): %d\n", n, TST(n, 0));

    return 0;
}
