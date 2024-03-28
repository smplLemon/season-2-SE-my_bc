#ifndef MY_BC_SOURCE_STACK_STRUCT_H_
#define MY_BC_SOURCE_STACK_STRUCT_H_

typedef struct stack_d {
    short value;
    struct stack_d* next;
} stack;

void push(stack** stack_list ,short op);
short pop(stack** s_list);

#endif