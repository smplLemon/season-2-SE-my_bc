#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./source/my_string_lib.h"
#include "./source/stack_struct.h"
#include "./source/queue_struct.h"
#include "./source/check_functions.h"

stack* stack_list = NULL;
queues* queue_list = NULL;

char* error(char* str) {
    if(check_error(str) == 1) {
        printf("parse error\n");
        return NULL;
    }
    if(check_for_parse_error(str) == 1) {
        printf("parse error\n");
        return NULL;
    }
    if(check_divide_error(str) == 1) {
        write(2, "divide by zero\n", 15);
        return NULL;
    }
    if(char_error(str) == 1) {
        printf("parse error\n");
        return NULL;
    }
    if(space(str) > 0){
        free_space(str);
        return str;
    }
    return str;
}

short oper(char op) {
    if(op == '(') return 0;
    if(op == '-' || op == '+') return 1;
    if(op == '/' || op == '*' || '%') return 2;
    return -1;
}

short count(short left, short right, char op) {
    if(op == '+') {
        push(&stack_list, left+right);
        return (left+right);
    }
    if(op == '-') {
        push(&stack_list, left-right);
        return (left-right);
    }
    if(op == '*') {
        push(&stack_list, left*right);
        return (left*right);
    }
    if(op == '/') {
        if(right == 0) return 1;
        push(&stack_list, left/right);
        return (left/right);
    }
    if(op == '%') {
        push(&stack_list, left%right);
        return (left%right);
    }
    return 0;
}

void counting() {
    while(1){
        while(queue_list->value == '\0' && queue_list != NULL) {
            push(&stack_list, queue_list->operant);
            free_que(&queue_list);
        }
        if(stack_list->next == NULL) {
            printf("%d\n",stack_list->value);
            return;
        }
        short right = pop(&stack_list);
        short left = pop(&stack_list);
        if(count(left, right, queue_list->value) == 1) {
            write(2, "divide by zero\n", 15);
            return;
        }
        if(queue_list->next != NULL){
            free_que(&queue_list);
        }
        else {
            printf("%d\n",stack_list->value);
            return;
        }
    }
}

void posfix(char* str) {
    short i = 0, ind, number;
    short flag = 0;
    short m = 0;
    short len = (my_strlen(str)+1);
    char* num = calloc(sizeof(char) ,len);
    while(i < my_strlen(str)) {
        if(my_isdigit(str[i]) == 1) {
            flag = 0;
            ind = 0;
            while(my_isdigit(str[i]) == 1){
                num[ind++] = str[i];
                i++;
            }
            number =  decimal(num);
            if(minus(str,i - my_strlen(num)) >= 2 || m == 1) number *= -1;
            add_que(&queue_list, '\0', number);
            m = 0;
            fill_null(num, len);
            i--;
        }
        else if(str[i] == '(') push(&stack_list, '(');
        else if(str[i] == ')'){
            while(stack_list->value != '('){
                add_que(&queue_list, stack_list->value, 0);
                pop(&stack_list);
            }
            pop(&stack_list);
        }   
        else if(i == 0 && (str[i] == '+' || str[i] == '-')) {
            if(str[i] == '-') m = 1;
        }
        else{
            flag += 1;
            if(flag < 2){
                while(stack_list != NULL && oper(stack_list->value) >= oper(str[i])){
                    add_que(&queue_list, stack_list->value, 0);
                    pop(&stack_list);
                }
                push(&stack_list, str[i]);
            }
        }
        i++;
    }
    free(num);
    while(stack_list != NULL){
        add_que(&queue_list,stack_list->value, 0);
        pop(&stack_list);
    }
}

int main(int ac, char** av){
    if(ac == 1){
        printf("Not content\n");
        return 1;
    }  
    if(error(av[1]) == NULL) return 1;
    else {
        char* str = calloc(sizeof(char), (my_strlen(av[1]) + 1));
        my_strcpy(str, error(av[1]));
        posfix(str);
        counting();
        free(str);
        return 0;
    }
}
