#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./source/my_string.h"
#include "./source/stack_struct.h"
#include "./source/queue_struct.h"
#include "./source/check_func.h"

stack* stack_list = NULL;
queues* queue_list = NULL;

char* check_error(char* string) {
    if(check(string) == 1) {
        printf("parse error\n");
        return NULL;
    }
    if(parse_error(string) == 1) {
        printf("parse error\n");
        return NULL;
    }
    if(divide_error(string) == 1) {
        printf("parse error\n");
        return NULL;
    }
    if(charector_error(string) == 1) {
        printf("parse error\n");
        return NULL;
    }
    if(check_space(string) > 0){
        un_space(string);
        return string;
    }
    return string;
}

short is_oper(char oper) {
    if(oper == '(')  return 0;
    if(oper == '-' || oper == '+') return 1;
    if(oper == '/' || oper == '*') return 2;
    return -1;
}

short counting(int left_side, int right_side, char operator) {
    short result = 0;
    switch (operator) {
        case '+':
            result = left_side + right_side;
            break;
        case '-':
            result = left_side - right_side;
            break;
        case '*':
            result = left_side * right_side;
            break;
        case '/':
            if(right_side == 0) {
                return 1;
            }
            result = left_side / right_side;
            break;
        case '%':
            result = left_side % right_side;
            break;
    }
    push(&stack_list, result);
    return 0;
}

void count_part() {
    while(1){
        while(queue_list->value == '\0' && queue_list != NULL) {
            push(&stack_list, queue_list->operant);
            clean_queue(&queue_list);
        }
        if(stack_list->next == NULL) {
            printf("%d\n",stack_list->value);
            return;
        }
        short right_side = pop(&stack_list);
        short left_side = pop(&stack_list);
        if(counting(left_side, right_side, queue_list->value) == 1) {
            printf("divide by zero\n");
            return;
        }
        if(queue_list->next != NULL){
            clean_queue(&queue_list);
        }
        else {
            printf("%d\n",stack_list->value);
            return;
        }
    }
}

void from_to_postfix(char* string) {
    short i = 0;
    short flag = 0;
    short minus = 0;
    short len = my_strlen(string)+1;
    while(i < my_strlen(string)){
        if(my_isdigit(string[i]) == 1){
            flag = 0;
            char* num = calloc(sizeof(char), len);
            short ind = 0;
            while(my_isdigit(string[i]) == 1){
                num[ind++] = string[i];
                i++;
            }
            short number =  char_to_decimal(num);
            if(check_minus(string,i - my_strlen(num)) >= 2 || minus == 1) number *= -1;
            add_queue(&queue_list, '\0', number);
            minus = 0;
            free(num);
            i--;
        }
        else if(string[i] == '(') push(&stack_list, '(');
        else if(string[i] == ')'){
            while(stack_list->value != '('){
                add_queue(&queue_list, stack_list->value, 0);
                pop(&stack_list);
            }
            pop(&stack_list);
        }    
        else if(i == 0 && (string[i] == '+' || string[i] == '-')) {
            if(string[i] == '-') minus = 1;
        }
        else{
            flag += 1;
            if(flag < 2){
                while(stack_list != NULL && is_oper(stack_list->value) >= is_oper(string[i])){
                    add_queue(&queue_list, stack_list->value, 0);
                    pop(&stack_list);
                }
                push(&stack_list, string[i]);
            }
        }
        i++;
    }
    while(stack_list != NULL){
        add_queue(&queue_list,stack_list->value, 0);
        pop(&stack_list);
    }
}

int main(int argc, char** argv) {
    if(argc == 1){
        printf("Not content\n");
        return 1;
    }
    if(check_error(argv[1]) == NULL) return 1;
    else {
        char* string = calloc(sizeof(char), (my_strlen(argv[1]) + 1));
        my_strcpy(string, check_error(argv[1]));
        from_to_postfix(string);
        count_part();
        free(string);
        return 0;
    }
}