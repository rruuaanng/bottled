#ifndef NONGFU_SPRING_MOTOR_CONTROL_ENCODER_H
#define NONGFU_SPRING_MOTOR_CONTROL_ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <common/types.h>

struct encoder_desc {
    char type;
#define ENCODER_DESC_TYPE_HALL              'H'
#define ENCODER_DESC_TYPE_INCREMENT         'I'

    u16 resolution;
    u64 timestamp;

    u16 current_angle;  
    u16 last_angle;
    u16 angle_range_end;
    u16 zero_point_pos;

    u64 current_cnt; // clear to zero when reaching max_cnt_end
    u64 last_cnt;   
    u64 max_cnt_end;

    void (*current_cnt_handle)(struct encoder_desc *);
};

#ifdef __cplusplus
}
#endif 

#endif // NONGFU_SPRING_MOTOR_CONTROL_ENCODER_H