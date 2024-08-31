#include <motor_control/coordinate.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    alpha_beta ab;
    q_d qd;
    float ia_f, ib_f, ic_f;
    float alpha_f, beta_f;
    float q_f, d_f;


    int wf = 15;
    qfmt_fvar(x1, 25.15, wf);
    qfmt_fvar(x2, 24.1851, wf);
    phase_i_var(i, x1, x2, 0);

    puts("========================qfixed========================");
    printf("A: %.4f \t B: %.4f \t C: %.4f\n", 
        q15_fmt_to_float(x1),
        q15_fmt_to_float(x2),
        q15_fmt_to_float(0));

    clarke_direct_3p_q15(&ab, i);
    printf("clarke -> alpha: %.4f \t beta: %.4f\n",
        q15_fmt_to_float(ab.alpha),
        q15_fmt_to_float(ab.beta));

    park_direct_2p_q15(&qd, ab, 30);
    printf("park -> q: %.4f \t d: %.4f\n",
        q15_fmt_to_float(qd.q),
        q15_fmt_to_float(qd.d));

    park_inverse_2p_q15(&ab, qd, 30);
    printf("park inverse -> alpha: %.4f \t beta: %.4f\n",
        q15_fmt_to_float(ab.alpha),
        q15_fmt_to_float(ab.beta));

    clarke_inverse_2p_q15(&i, ab);
    printf("clarke inverse -> A: %.4f \t B: %.4f \t C: %.4f \n",
        q15_fmt_to_float(i.ia),
        q15_fmt_to_float(i.ib),
        q15_fmt_to_float(i.ic));

    puts("========================float========================");
    float alpha_float, beta_float;
    float q_float, d_float;
    float ia, ib, ic;

    ia = 25.15; ib = 24.1851; ic = 0;
    printf("A: %.4f \t B: %.4f \t C: %.4f\n", ia, ib, ic);

    clarke_direct_3p(&alpha_float, &beta_float, ia, ib);
    printf("clarke -> alpha: %.4f \t beta: %.4f\n", alpha_float, beta_float);

    park_direct_2p(&q_float, &d_float, alpha_float, beta_float, 30);
    printf("park -> q: %.4f \t d: %.4f\n", q_float, d_float);

    park_inverse_2p(&alpha_float, &beta_float, q_float, d_float, 30);
    printf("park inverse -> alpha: %.4f \t beta: %.4f\n", alpha_float, beta_float);

    clarke_inverse_2p(&ia, &ib, &ic, alpha_float, beta_float);
    printf("clarke inverse -> A: %.4f \t B: %.4f \t C: %.4f \n", ia, ib, ic);

    return 0;
}
