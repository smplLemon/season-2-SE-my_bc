#include "stack_struct.h"
#include <stdlib.h>

void push(stack** stack_list ,short op) {
    stack* new = (stack*)malloc(sizeof(stack));
    new->value = op;
    new->next = *stack_list;
    *stack_list = new;
}

short pop(stack** s_list) {
    stack* temp = *s_list;
    short num = temp->value;
    *s_list = (*s_list)->next;
    free(temp);
    return num;
}   
