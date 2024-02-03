#include "./stack.h"

Stack *Init_Stack() {
    Stack *new_stack = malloc(sizeof(Stack));
    new_stack->data[0] = 0.0;
    new_stack->size = 0;
    return new_stack;
}

double Peek_Stack(Stack stack) {
    double result = 0.0;
    if (!Is_Stack_Empty(stack)) {
        result = stack.data[stack.size];
    }
    return result;
}

int Is_Stack_Empty(Stack stack) {
    return stack.size == 0;
}

int Is_Stack_Full(Stack stack) {
    return stack.size == MAX_STACK_SIZE - 1;
}

void Push_Stack(Stack *stack, double new_value) {
    if (stack) {
        stack->size++;
        stack->data[stack->size] = new_value;
    }
}

double Pop_Stack(Stack *stack) {
    double poped = 0.0;
    if (stack && stack->size != 0) {
        poped = stack->data[stack->size];
        stack->data[stack->size] = 0.0;
        stack->size--;
    }
    return poped;
}

void Delete_Stack(Stack *stack) {
    if (stack) {
        while (stack->size != 0) {
            Pop_Stack(stack);
        }
        free(stack);
    }
}
