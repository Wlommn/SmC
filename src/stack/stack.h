#ifndef SRC_STACK_STACK_H_
#define SRC_STACK_STACK_H_

#include <stdlib.h>

#include "../common_def.h"

#define MAX_STACK_SIZE 256

typedef struct Stack {
  double data[MAX_STACK_SIZE];
  int size;
} Stack;

extern Stack *Init_Stack();
extern double Peek_Stack(Stack stack);
extern int Is_Stack_Empty(Stack stack);
extern int Is_Stack_Full(Stack stack);
extern void Push_Stack(Stack *stack, double new_value);
extern double Pop_Stack(Stack *stack);
extern void Delete_Stack(Stack *stack);

#endif  //  SRC_STACK_STACK_H_