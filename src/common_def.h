#ifndef SRC_COMMON_DEF_H_
#define SRC_COMMON_DEF_H_

#include <stdbool.h>

#define IO_MAX_SIZE 256

typedef enum OPERATORS {
    null_op = 65,
    umin_op,
    uplus_op,
    add_op,
    sub_op,
    mul_op,
    div_op,
    sin_op,
    cos_op,
    tan_op,
    acos_op,
    asin_op,
    atan_op,
    scale_op,
    ln_op,
    log_op,
    sqrt_op
} operators_t;

extern bool is_function;
extern char postfix[IO_MAX_SIZE * 2];

extern char* infix_to_postfix(char *infix);

extern double calc(char *postfix, double x);


#endif  //  SRC_COMMON_DEFS_H_