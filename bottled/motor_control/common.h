#ifndef NONGFU_SPRING_MOTOR_CONTROL_COMMON_H
#define NONGFU_SPRING_MOTOR_CONTROL_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

//
// import standard library
//
#include <stdint.h>
#include <stdbool.h>
#include <common/q_fixed.h>

//
// physical structure
//
typedef struct {
    int32_t ia;
    int32_t ib;
    int32_t ic;
}phase_i;

typedef struct {
    int32_t alpha;
    int32_t beta;
}alpha_beta;

typedef struct {
    int32_t q;
    int32_t d;
}q_d;

//
// define a physical variable
//
#define phase_i_var(name, a, b, c) \
    phase_i name = {a, b, c}
#define alpha_beta_var(name, alpha, beta) \
    alpha_beta name = {alpha, beta}
#define qd_var(name, q, d) \
    qd name = {q, d}

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_COMMON_H