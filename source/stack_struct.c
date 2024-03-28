#include <stdlib.h>
#include "stack_struct.h"

void push(stack** stack_list ,short option) {
    stack* new = (stack*)malloc(sizeof(stack));
    new->value = option;
    new->next = *stack_list;
    *stack_list = new;
}

short pop(stack** stack_list) {
    stack* temp = *stack_list;
    short ret_num = temp->value;
    *stack_list = (*stack_list)->next;
    free(temp);
    return ret_num;
}   