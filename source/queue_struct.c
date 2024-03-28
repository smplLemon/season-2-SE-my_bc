#include "queue_struct.h"
#include <stdlib.h>

void add_que(queues** opers, char new_op, short num) {
    queues* new = (queues*)malloc(sizeof(queues));
    new->value = new_op;
    new->operant = num; 
    new->next = NULL;
    if(*opers == NULL) *opers = new;
    else {
        queues* loop = *opers;
        while(loop->next != NULL) loop = loop->next;
        loop->next = new;
    }
}

void free_que(queues** q_list) {
    queues* temp = *q_list;
    *q_list = (*q_list)->next;
    free(temp);
}
