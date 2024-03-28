#ifndef QUEUE_STRUCT_H
#define QUEUE_STRUCT_H

typedef struct queue {
    char value;
    short operant;
    struct queue* next;
}queues;

void add_queue(queues** operator, char new_oper, short num);
void clean_queue(queues** queue_list);

#endif