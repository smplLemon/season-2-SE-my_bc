#ifndef MY_BC_SOURCE_QUEUE_STRUCT_H_
#define MY_BC_SOURCE_QUEUE_STRUCT_H_

typedef struct queue {
    char value;
    short operant;
    struct queue* next;
} queues;

void add_que(queues** opers, char new_op, short num);
void free_que(queues** q_list);

#endif