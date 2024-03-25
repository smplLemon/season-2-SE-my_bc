#include "../h/queue_stack.h"
#include <stdlib.h>

void add_que(queue** operators, char new_operator, short num) {
    queue* new = (queue*)malloc(sizeof(queue));
    new->value = new_operator;
    new->operant = num; 
    new->next = NULL;
    if(*operators == NULL) *operators = new;
    else {
        queue* loop = *operators;
        while(loop->next != NULL) loop = loop->next;
        loop->next = new;
    }
}

void free_que(queue** list) {
    queue* temp = *list;
    *list = (*list)->next;
    free(temp);
}

void push(stack** stack_list ,short option) {
    stack* new = (stack*)malloc(sizeof(stack));
    new->value = option;
    new->next = *stack_list;

    *stack_list = new;
}

short pop(stack** list) {
    stack* temp = *list;
    short num = temp->value;
    *list = (*list)->next;
    free(temp);
    return num;
}   
