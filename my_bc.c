#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./h/my_string.h"
#include "./h/queue_stack.h"
#include "./h/check_function.h"
stack* stack_list = NULL;
queue* queue_list = NULL;

short error(char* str) {
    int* arr = (int*)malloc(sizeof(int)*3);
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    short i;
    short ind1 = 0; short ind2 = 0;
    for(i = 0; str[i]; i++) {
        if(str[i] == '(' && str[i+1] == ')') arr[0] = 1;
        if(str[i] == '/' && str[i+1] == '0') arr[1] = 1;
        if(check(str[i]) == 1) {printf("1\n");arr[2] = 1;}
        if(i != 0 && str[i] == '(' && my_isdigit(str[i-1])) {printf("2\n");arr[2] = 1;}
        if(str[i] == ')' && my_isdigit(str[i+1])) {printf("3\n");arr[2] = 1;}
        if(i != 0 && str[i] == '+') {
            if(str[i+1] == ')' || operator(str[i+1]) > 1) {printf("4\n");arr[2] = 1;}
            if(i!=0) {
                if(operator(str[i-1]) >1&& operator(str[i+1])>1) {printf("6\n");arr[2] = 1;}
            }
        }
        if(i != 0 && str[i] == '-') {
            if(str[i+1] == ')' || operator(str[i+1]) > 1) {printf("7\n");arr[2] = 1;}
            if(i!=0) {
                if(operator(str[i-1])>1&& operator(str[i+1])>1) {printf("9\n");arr[2] = 1;}
            }
        }
        if(i != 0 && str[i] == '*') {
            if(str[i+1] == ')' || operator(str[i+1]) < 1) {printf("10\n");arr[2] = 1;}
            if(i!=0) {
                if(str[i-1] == '(' || operator(str[i-1]) < 1) {printf("11\n");arr[2] = 1;}
            }
        }
        if(i != 0 && str[i] == '/') {
            if(str[i+1] == ')' || operator(str[i-1]) < 1) {printf("12\n");arr[2] = 1;}
            if(i!=0) {
                if(str[i-1] == '(' || operator(str[i-1]) < 1){printf("13\n");arr[2] = 1;}
            }
        }
        if(i != 0 && str[i] == '%') {
            if(str[i+1] == ')' || operator(str[i+1]) > 0) {printf("15\n");arr[2] = 1;}
            if(i!=0) {
                if(str[i-1] == '(' || operator(str[i-1]) > 0) {printf("16\n");arr[2] = 1;}
            }
        }
        if(str[i] == '(') ind1++;
        if(str[i] == ')') ind2++;
    }
    if(ind1 != ind2) {printf("18\n");arr[2] = 1;}
    if(arr[0] ==1 || arr[1] == 1 || arr[2] == 1) {
        if(arr[0] == 1) printf("parse error\n");
        if(arr[1] == 1) printf("divide by zero\n");
        if(arr[2] == 1) printf("Wrong content\n");
        free(arr);
        return 1;
    }
    free(arr);
    return 0;
}

short count_part(short left, short right, char oper) {
    short result = 0;
    if(oper == '+') result = left+right;
    if(oper == '-') result = left-right;
    if(oper == '*') result = left*right;
    if(oper == '/') result = left/right;
    if(oper == '%') result = left%right;
    push(&stack_list, result);
    return 0;
}

void count() {
    while(1){
        while(queue_list->value == '\0' && queue_list != NULL) {
            push(&stack_list, queue_list->operant);
            free_que(&queue_list);
        }
        if(stack_list->next == NULL && stack_list != NULL) {
            printf("%d\n",stack_list->value);
            return;
        }
           
        short right = pop(&stack_list);
        short left = pop(&stack_list);
        count_part(left, right, queue_list->value);
        if(queue_list->next != NULL){
            free_que(&queue_list);
        }
        else  {
            printf("%d\n",stack_list->value);
            return;
        }
    }
}

void str_to_postfix(char* str) {
    short i = 0;
    short flag = 0;
    short minus = 0;
    while(i < my_strlen(str)){
        if(my_isdigit(str[i]) == 1){
            flag = 0;
            char* num = calloc(sizeof(char) , (my_strlen(str) + 1));
            short ind = 0;
            while(my_isdigit(str[i]) == 1){
                num[ind++] = str[i];
                i++;
            }
            short number =  char_to_decimal(num);
            if(check_minus(str, i - my_strlen(num)) >= 2 || minus == 1) number *= -1;
            add_que(&queue_list, '\0', number);
            minus = 0;
            free(num);
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
            if(str[i] == '-') minus = 1;
        }
        else{
            flag += 1;
            if(flag < 2){
                while(stack_list != NULL && operator(stack_list->value) >= operator(str[i])){
                    add_que(&queue_list, stack_list->value, 0);
                    pop(&stack_list);
                }
                push(&stack_list, str[i]);
            }
        }
        i++;
    }

    while(stack_list != NULL){
        add_que(&queue_list,stack_list->value, 0);
        pop(&stack_list);
    }
}

int main(int ac, char** av) {
    if(ac == 1){
        printf("Not content\n");
        return 1;
    }
    free_space(av[1]);
    if(error(av[1]) == 1)  return 1;
    else {
        str_to_postfix(av[1]);
        count();
        return 0;
    }
}
