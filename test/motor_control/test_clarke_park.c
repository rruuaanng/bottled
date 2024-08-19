#include <motor_control/clarke.h>
#include <motor_control/park.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    alpha_beta ab;
    q_d qd;
    float ia_f, ib_f, ic_f;
    float alpha_f, beta_f;
    float q_f, d_f;


    int wf = 15;
    qfixed_fvar(x1, 25.15, wf);
    qfixed_fvar(x2, 24.1851, wf);
    phase_i_var(i, x1, x2, 0);

    puts("========================qfixed========================");
    qfixed_to_float(&ia_f, i.ia, wf);
    qfixed_to_float(&ib_f, i.ib, wf);
    qfixed_to_float(&ic_f, i.ic, wf);
    printf("A: %.4f \t B: %.4f \t C: %.4f\n", ia_f, ib_f, ic_f);

    clarke_direct_3p_q15(&ab, i);
    qfixed_to_float(&alpha_f, ab.alpha, wf);
    qfixed_to_float(&beta_f, ab.beta, wf);
    printf("clarke -> alpha: %.4f \t beta: %.4f\n", alpha_f, beta_f);

    park_direct_2p_q15(&qd, ab, 30);
    qfixed_to_float(&q_f, qd.q, wf);
    qfixed_to_float(&d_f, qd.d, wf);
    printf("park -> q: %.4f \t d: %.4f\n", q_f, d_f);

    park_inverse_2p_q15(&ab, qd, 30);
    qfixed_to_float(&alpha_f, ab.alpha, wf);
    qfixed_to_float(&beta_f, ab.beta, wf);
    printf("park inverse -> alpha: %.4f \t beta: %.4f\n", alpha_f, beta_f);

    clarke_inverse_2p_q15(&i, ab);
    qfixed_to_float(&ia_f, i.ia, wf);
    qfixed_to_float(&ib_f, i.ib, wf);
    qfixed_to_float(&ic_f, i.ic, wf);
    printf("clarke inverse -> A: %.4f \t B: %.4f \t C: %.4f \n", ia_f, ib_f, ic_f);

    puts("========================float========================");
    float alpha_float, beta_float;
    float q_float, d_float;
    float ia, ib, ic;

    ia = 25.15; ib = 24.1851; ic = 0;
    printf("A: %.4f \t B: %.4f \t C: %.4f\n", ia, ib, ic);

    clarke_direct_3p_float(&alpha_float, &beta_float, ia, ib);
    printf("clarke -> alpha: %.4f \t beta: %.4f\n", alpha_float, beta_float);

    park_direct_2p_float(&q_float, &d_float, alpha_float, beta_float, 30);
    printf("park -> q: %.4f \t d: %.4f\n", q_float, d_float);

    park_inverse_2p_float(&alpha_float, &beta_float, q_float, d_float, 30);
    printf("park inverse -> alpha: %.4f \t beta: %.4f\n", alpha_float, beta_float);

    clarke_inverse_2p_float(&ia, &ib, &ic, alpha_float, beta_float);
    printf("clarke inverse -> A: %.4f \t B: %.4f \t C: %.4f \n", ia, ib, ic);

    return 0;
}
