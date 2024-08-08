#include <motor_control/clarke.h>
#include <motor_control/park.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    alpha_beta ab;
    q_d qd;

    int wf = 15;
    qfixed_fvar(x1, 25.15, wf);
    qfixed_fvar(x2, 24.1851, wf);
    phase_i_var(i, x1, x2, 0);

    puts("========================qfixed========================");
    printf("A: %.4f \t B: %.4f \t C: %.4f\n",
                q15_fixed_to_float(i.ia),
                q15_fixed_to_float(i.ib),
                q15_fixed_to_float(i.ic));

    clarke_direct_3p_q15(&ab, i);
    printf("clarke -> alpha: %.4f \t beta: %.4f\n",
        q15_fixed_to_float(ab.alpha),
        q15_fixed_to_float(ab.beta));

    park_direct_2p_q15(&qd, ab, 30);
    printf("park -> q: %.4f \t d: %.4f\n",
        q15_fixed_to_float(qd.q),
        q15_fixed_to_float(qd.d));

    park_inverse_2p_q15(&ab, qd, 30);
    printf("park inverse -> alpha: %.4f \t beta: %.4f\n",
        q15_fixed_to_float(ab.alpha),
        q15_fixed_to_float(ab.beta));

    clarke_inverse_2p_q15(&i, ab);
    printf("clarke inverse -> A: %.4f \t B: %.4f \t C: %.4f \n",
            q15_fixed_to_float(i.ia),
            q15_fixed_to_float(i.ib),
            q15_fixed_to_float(i.ic));

    puts("========================float========================");
    alpha_beta ab_float;
    q_d qd_float;
    phase_i_fvar(i_float, 25.15, 24.1851, 0);
    
    printf("A: %.4f \t B: %.4f \t C: %.4f\n",
                i_float.ia_float,
                i_float.ib_float,
                i_float.ic_float);

    clarke_direct_3p_float(&ab_float, i_float);

    printf("clarke -> alpha: %.4f \t beta: %.4f\n",
        ab_float.alpha_float,
        ab_float.beta_float);

    park_direct_2p_float(&qd_float, ab_float, 30);
    printf("park -> q: %.4f \t d: %.4f\n",
        qd_float.q_float,
        qd_float.d_float);

    park_inverse_2p_float(&ab_float, qd_float, 30);
    printf("park inverse -> alpha: %.4f \t beta: %.4f\n",
        ab_float.alpha_float,
        ab_float.beta_float);

    clarke_inverse_2p_float(&i_float, ab_float);
    printf("clarke inverse -> A: %.4f \t B: %.4f \t C: %.4f \n",
            i_float.ia_float,
            i_float.ib_float,
            i_float.ic_float);


    return 0;
}
