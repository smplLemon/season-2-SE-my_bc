#ifndef MY_BC_H_QUEUE_STACK_H_
#define MY_BC_H_QUEUE_STACK_H_

typedef struct queue_l
{
    char value;
    short operant;
    struct queue_l* next;
}queue;

void add_que(queue** operators, char new_operator, short num);
void free_que(queue** list);

typedef struct stack_l
{
    short value;
    struct stack_l* next;
} stack;

void push(stack** stack_list ,short option);
short pop(stack** list);

#endif
