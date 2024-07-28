#ifndef YIBAO_COMMON_BIT_H
#define YIBAO_COMMON_BIT_H

#ifdef __cplusplus
extern "C" {
#endif

#define BIT(i)              (1 << (i))

#define TST(n, i)           ((n) & BIT(i))
#define SET(n, i)           ((n) |= BIT(i))
#define CLR(n, i)           ((n) &= ~BIT(i)) 

#ifdef __cplusplus
}
#endif 


#endif // YIBAO_COMMON_BIT_H