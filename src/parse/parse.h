#ifndef SRC_PARSE_PARSE_H_
#define SRC_PARSE_PARSE_H_

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#include "../common_def.h"
#include "../stack/stack.h"

void clean_spaces(char* str);
char* infix_to_postfix(char *infix);
bool is_operator(char ch);
int get_priority(operators_t op);

#endif  //  SRC_PARSE_PARSE_H_