#ifndef STACK_STRUCT_H
#define STACK_STRUCT_H

typedef struct stack_d {
    short value;
    struct stack_d* next;
} stack;

void push(stack** stack_list ,short option);
short pop(stack** stack_list);

#endif