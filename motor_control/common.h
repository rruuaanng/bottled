#ifndef NONGFU_SPRING_MOTOR_CONTROL_COMMON_H
#define NONGFU_SPRING_MOTOR_CONTROL_COMMON_H

//
// import standard library
//
#include <stdint.h>
#include <stdbool.h>


typedef struct {
    int32_t ia;
    int32_t ib;
    int32_t ic;
}phase_v;

#define phase_v(name, a, b, c) \
    phase_v name = {a, b, c}

typedef struct {
    int32_t alpha;
    int32_t beta;
}alpha_beta;

#define alpha_beta(name, alpha, beta) \
    alpha_beta name = {alpha, beta}

typedef struct {
    int32_t q;
    int32_t d;
}q_d;

#define qd(name, q, d) \
    qd name = {q, d}


#endif // NONGFU_SPRING_MOTOR_CONTROL_COMMON_H