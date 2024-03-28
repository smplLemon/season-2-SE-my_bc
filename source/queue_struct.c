#include "queue_struct.h"
#include <stdlib.h>

void add_queue(queues** operator, char new_oper, short num) {
    queues* new = (queues*)malloc(sizeof(queues));
    new->value = new_oper;
    new->operant = num; 
    new->next = NULL;
    if(*operator == NULL) *operator = new;
    else {
        queues* for_loop = *operator;
        while(for_loop->next != NULL) for_loop = for_loop->next;
        for_loop->next = new;
    }
}

void clean_queue(queues** queue_list) {
    queues* temp = *queue_list;
    *queue_list = (*queue_list)->next;
    free(temp);
}
