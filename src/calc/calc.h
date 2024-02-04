#ifndef SRC_CALC_CALC_H_
#define SRC_CALC_CALC_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../common_def.h"
#include "../stack/stack.h"

#define PI 3.14159265358979323846

#define degToRad(angleInDegrees) ((angleInDegrees) * PI / 180.0)

double calc(char *postfix, double x);
bool is_binary_op(char ch);
double binary_operation(char ch, double op1, double op2);
bool is_unary_op(char ch);
double unary_operation(char ch, double op);

#endif  //  SRC_CALC_CALC_H_
