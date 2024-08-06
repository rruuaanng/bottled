#include <common/q_fixed.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    // 
    // Q15 test
    //
    q_fixed x1, x2;
    float x1_f, x2_f;
    q_fixed sin, cos;
    x1_f = 1.537;
    x2_f = 0.4;

    // Q15
    puts("====================Q15=====================");
    x1 = q15(x1_f);
    x2 = q15(x2_f);
    
    printf("add (q15_fixed): %d + %d = a%d \n",x1, x2, q15_fixed_add(x1, x2));
    printf("add (q15_fixed): %.4f + %.4f = %.4f \n",
            q15_fixed_to_float(x1), 
            q15_fixed_to_float(x2), 
            q15_fixed_to_float(q15_fixed_add(x1, x2)));

    printf("sub (q15_fixed): %d - %d = %d \n",x1, x2, q15_fixed_sub(x1, x2));
    printf("sub (q15_fixed): %.4f - %.4f = %.4f \n",
            q15_fixed_to_float(x1), 
            q15_fixed_to_float(x2), 
            q15_fixed_to_float(q15_fixed_sub(x1, x2)));

    printf("mul (q15_fixed): %d * %d = %d \n",x1, x2, q15_fixed_mul(x1, x2));
    printf("mul (q15_fixed): %.4f * %.4f = %.4f \n",
            q15_fixed_to_float(x1), 
            q15_fixed_to_float(x2), 
            q15_fixed_to_float(q15_fixed_mul(x1, x2)));

    printf("div (q15_fixed): %d / %d = %d \n",x1, x2, q15_fixed_div(x1, x2));
    printf("div (q15_fixed): %.4f / %.4f = %.4f \n",
            q15_fixed_to_float(x1), 
            q15_fixed_to_float(x2), 
            q15_fixed_to_float(q15_fixed_div(x1, x2)));

    printf("gt (q15_fixed): %d\n", q15_fixed_gt(x1, x2));
    printf("gte (q15_fixed): %d\n", q15_fixed_gte(x1, x2));
    printf("lt (q15_fixed): %d\n", q15_fixed_lt(x1, x2));
    printf("lte (q15_fixed): %d\n", q15_fixed_lte(x1, x2));
    printf("eq (q15_fixed): %d\n", q15_fixed_eq(x1, x2));
    printf("ne (q15_fixed): %d\n", q15_fixed_ne(x1, x2));
    
    // Q14
    puts("====================Q14======================");
    x1 = q14(x1_f);
    x2 = q14(x2_f);
    printf("add (q14_fixed): %d + %d = %d \n",x1, x2, q14_fixed_add(x1, x2));
    printf("add (q14_fixed): %.4f + %.4f = %.4f \n",
            q14_fixed_to_float(x1), 
            q14_fixed_to_float(x2), 
            q14_fixed_to_float(q14_fixed_add(x1, x2)));

    printf("sub (q14_fixed): %d - %d = %d \n",x1, x2, q14_fixed_sub(x1, x2));
    printf("sub (q14_fixed): %.4f - %.4f = %.4f \n",
            q14_fixed_to_float(x1), 
            q14_fixed_to_float(x2), 
            q14_fixed_to_float(q14_fixed_sub(x1, x2)));

    printf("mul (q14_fixed): %d * %d = %d \n",x1, x2, q14_fixed_mul(x1, x2));
    printf("mul (q14_fixed): %.4f * %.4f = %.4f \n",
            q14_fixed_to_float(x1), 
            q14_fixed_to_float(x2), 
            q14_fixed_to_float(q14_fixed_mul(x1, x2)));

    printf("div (q14_fixed): %d / %d = %d \n",x1, x2, q14_fixed_div(x1, x2));
    printf("div (q14_fixed): %.4f / %.4f = %.4f \n",
            q14_fixed_to_float(x1), 
            q14_fixed_to_float(x2), 
            q14_fixed_to_float(q14_fixed_div(x1, x2)));

    printf("gt (q14_fixed): %d\n", q14_fixed_gt(x1, x2));
    printf("gte (q14_fixed): %d\n", q14_fixed_gte(x1, x2));
    printf("lt (q14_fixed): %d\n", q14_fixed_lt(x1, x2));
    printf("lte (q14_fixed): %d\n", q14_fixed_lte(x1, x2));
    printf("eq (q14_fixed): %d\n", q14_fixed_eq(x1, x2));
    printf("ne (q14_fixed): %d\n", q14_fixed_ne(x1, x2));

    // Q12
    puts("====================Q12=====================");
    x1 = q12(x1_f);
    x2 = q12(x2_f);
    printf("add (q12_fixed): %d + %d = %d \n",x1, x2, q12_fixed_add(x1, x2));
    printf("add (q12_fixed): %.4f + %.4f = %.4f \n",
            q12_fixed_to_float(x1), 
            q12_fixed_to_float(x2), 
            q12_fixed_to_float(q12_fixed_add(x1, x2)));

    printf("sub (q12_fixed): %d - %d = %d \n",x1, x2, q12_fixed_sub(x1, x2));
    printf("sub (q12_fixed): %.4f - %.4f = %.4f \n",
            q12_fixed_to_float(x1), 
            q12_fixed_to_float(x2), 
            q12_fixed_to_float(q12_fixed_sub(x1, x2)));

    printf("mul (q12_fixed): %d * %d = %d \n",x1, x2, q12_fixed_mul(x1, x2));
    printf("mul (q12_fixed): %.4f * %.4f = %.4f \n",
            q12_fixed_to_float(x1), 
            q12_fixed_to_float(x2), 
            q12_fixed_to_float(q12_fixed_mul(x1, x2)));

    printf("div (q12_fixed): %d / %d = %d \n",x1, x2, q12_fixed_div(x1, x2));
    printf("div (q12_fixed): %.4f / %.4f = %.4f \n",
            q12_fixed_to_float(x1), 
            q12_fixed_to_float(x2), 
            q12_fixed_to_float(q12_fixed_div(x1, x2)));

    printf("gt (q12_fixed): %d\n", q12_fixed_gt(x1, x2));
    printf("gte (q12_fixed): %d\n", q12_fixed_gte(x1, x2));
    printf("lt (q12_fixed): %d\n", q12_fixed_lt(x1, x2));
    printf("lte (q12_fixed): %d\n", q12_fixed_lte(x1, x2));
    printf("eq (q12_fixed): %d\n", q12_fixed_eq(x1, x2));
    printf("ne (q12_fixed): %d\n", q12_fixed_ne(x1, x2));

    // Q7
    puts("====================Q7======================");
    x1 = q7(x1_f);
    x2 = q7(x2_f);
    printf("add (q7_fixed): %d + %d = %d \n",x1, x2, q7_fixed_add(x1, x2));
    printf("add (q7_fixed): %.4f + %.4f = %.4f \n",
            q7_fixed_to_float(x1), 
            q7_fixed_to_float(x2), 
            q7_fixed_to_float(q7_fixed_add(x1, x2)));

    printf("sub (q7_fixed): %d - %d = %d \n",x1, x2, q7_fixed_sub(x1, x2));
    printf("sub (q7_fixed): %.4f - %.4f = %.4f \n",
            q7_fixed_to_float(x1), 
            q7_fixed_to_float(x2), 
            q7_fixed_to_float(q7_fixed_sub(x1, x2)));

    printf("mul (q7_fixed): %d * %d = %d \n",x1, x2, q7_fixed_mul(x1, x2));
    printf("mul (q7_fixed): %.4f * %.4f = %.4f \n",
            q7_fixed_to_float(x1), 
            q7_fixed_to_float(x2), 
            q7_fixed_to_float(q7_fixed_mul(x1, x2)));

    printf("div (q7_fixed): %d / %d = %d \n",x1, x2, q7_fixed_div(x1, x2));
    printf("div (q7_fixed): %.4f / %.4f = %.4f \n",
            q7_fixed_to_float(x1), 
            q7_fixed_to_float(x2), 
            q7_fixed_to_float(q7_fixed_div(x1, x2)));

    printf("gt (q7_fixed): %d\n", q7_fixed_gt(x1, x2));
    printf("gte (q7_fixed): %d\n", q7_fixed_gte(x1, x2));
    printf("lt (q7_fixed): %d\n", q7_fixed_lt(x1, x2));
    printf("lte (q7_fixed): %d\n", q7_fixed_lte(x1, x2));
    printf("eq (q7_fixed): %d\n", q7_fixed_eq(x1, x2));
    printf("ne (q7_fixed): %d\n", q7_fixed_ne(x1, x2));

    // math
    puts("====================math======================");\
    printf("abs (q15_fixed): %d %d\n", q_fixed_math_abs(q15(-1.4612)), q15(-1.4612));
    printf("abs (q14_fixed): %d %d\n", q_fixed_math_abs(q14(-1.4612)), q14(-1.4612));
    printf("abs (q12_fixed): %d %d\n", q_fixed_math_abs(q12(-1.4612)), q12(-1.4612));
    printf("abs (q7_fixed): %d %d\n", q_fixed_math_abs(q7(-1.4612)), q7(-1.4612));

    printf("sign (q15_fixed): %d %d\n", q_fixed_math_sign(q15(1.4612)), q15(1.4612));
    printf("sign (q14_fixed): %d %d\n", q_fixed_math_sign(q14(1.4612)), q14(1.4612));
    printf("sign (q12_fixed): %d %d\n", q_fixed_math_sign(q12(1.4612)), q12(1.4612));
    printf("sign (q7_fixed): %d %d\n", q_fixed_math_sign(q7(-1.4612)), q7(-1.4612));

    q_fixed_math_sin_cos_q15(&sin, &cos, 30);
    printf("sin (30): %.4f cos (30): %.4f\n", 
            q15_fixed_to_float(sin), q15_fixed_to_float(cos));
    q_fixed_math_sin_cos_q15(&sin, &cos, 45);
    printf("sin (45): %.4f cos (45): %.4f\n", 
            q15_fixed_to_float(sin), q15_fixed_to_float(cos));
    q_fixed_math_sin_cos_q15(&sin, &cos, 60);
    printf("sin (60): %.4f cos (60): %.4f\n", 
            q15_fixed_to_float(sin), q15_fixed_to_float(cos));

    return 0;
}
