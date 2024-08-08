#ifndef NONGFU_SPRING_MOTOR_CONTROL_COMMON_H
#define NONGFU_SPRING_MOTOR_CONTROL_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <common/types.h>
#include <common/qfixed.h>
#include <math.h>

//
// physical structure
//
typedef struct {
    int32_t ia;
    float ia_float;
    int32_t ib;
    float ib_float;
    int32_t ic;
    float ic_float;
}phase_i;

typedef struct {
    int32_t alpha;
    float alpha_float;
    int32_t beta;
    float beta_float;
}alpha_beta;

typedef struct {
    int32_t q;
    float q_float;
    int32_t d;
    float d_float;
}q_d;

//
// define a physical variable
//
#define phase_i_var(name, a, b, c) \
    phase_i name = {.ia = a, .ib = b, .ic = c}
#define phase_i_fvar(name, a, b, c) \
    phase_i name = {.ia_float = a, .ib_float = b, .ic_float = c}
    
#define alpha_beta_var(name, alpha, beta) \
    alpha_beta name = {.alpha = alpha, .beta = beta}
#define alpha_beta_fvar(name, alpha, beta) \
    alpha_beta name = {.alpha_float = alpha, .beta_float = beta}

#define qd_var(name, q, d) \
    q_d name = {.q = q, .d = d}
#define qd_fvar(name, q, d) \
    q_d name = {.q_float = q, .d_float = d}

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_COMMON_H