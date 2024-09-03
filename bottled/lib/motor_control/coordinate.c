#include <motor_control/coordinate.h>


// 
// clarke transform
//
// assuming three-phase balance, then A+B+C=0
// 1. alpha = Ia - 1/2Ib - 1/2Ic
// 2. due to B=C, then 1/2Ib - 1/2Ic = 0
// 3. alpha = Ia - 0
// 4. alpha = Ia
//
// 1. beta = 2/3 * (sqrt(3)/2Ib - sqrt(3)/2Ic)
// 2. A+B+C=0, then C=-A-B
// 3. beta = 2/3 * (sqrt(3)/2Ib + sqrt(3)/2IA + sqrt(3)/2Ib)
// 4. beta = 2/3 * (sqrt(3)/2Ia + sqrt(3)Ib)
// 5. beta = sqrt(3)/3Ia + 2sqrt(3)/3Ib
void clarke_direct_3p_q15(alpha_beta *ab, phase_i i)
{
    qfmt x0, x1;
    const qfmt sqrt3 = Q15_FMT_SQRT3; // q15
    
    ab->alpha = i.ia;
    x0 = q15_fmt_mul(sqrt3, i.ia) / 3;
    x1 = q15_fmt_mul(2 * sqrt3, i.ib) / 3;
    ab->beta = x0 + x1;
}

//
// clarke inverse transform
//
void clarke_inverse_2p_q15(phase_i *i, alpha_beta ab)
{
    const qfmt sqrt3 = Q15_FMT_SQRT3; // q15

    i->ia = ab.alpha;
    i->ib = qfmt_add(0 - ab.alpha, q15_fmt_mul(sqrt3, ab.beta)) / 2;
    i->ic = qfmt_sub(0 - ab.alpha, q15_fmt_mul(sqrt3, ab.beta)) / 2;
}

//
// park transform
//
void park_direct_2p_q15(q_d *qd, alpha_beta ab, int theta_deg)
{
    qfmt x0, x1;
    qfmt sin_theta, cos_theta;

    qfmt_math_sin_cos_q15(&sin_theta, &cos_theta, theta_deg);

    x0 = q15_fmt_mul(ab.alpha, cos_theta);
    x1 = q15_fmt_mul(ab.beta, sin_theta);
    qd->d = qfmt_add(x0, x1);
    
    x0 = q15_fmt_mul(-ab.alpha, sin_theta);
    x1 = q15_fmt_mul(ab.beta, cos_theta);
    qd->q = qfmt_add(x0, x1);
}

//
// park inverse transform
//
void park_inverse_2p_q15(alpha_beta *ab, q_d qd, int theta_deg)
{
    qfmt x0, x1;
    qfmt sin_theta, cos_theta;

    qfmt_math_sin_cos_q15(&sin_theta, &cos_theta, theta_deg);
    x0 = q15_fmt_mul(qd.d, cos_theta);
    x1 = q15_fmt_mul(qd.q, sin_theta);
    ab->alpha = qfmt_sub(x0, x1);
    
    x0 = q15_fmt_mul(qd.d, sin_theta);
    x1 = q15_fmt_mul(qd.q, cos_theta);
    ab->beta = qfmt_add(x0, x1);
}