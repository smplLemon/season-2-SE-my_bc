#include "my_string.h"

short check_for_parse_error(char* str) {
    for(short i = 0; i < my_strlen(str); i++) {
       if(str[i] == '(' && str[i + 1] == ')') return 1;
    }
    return 0;
}

short check_error(char* str) {
    short count = 0;
    for(short i = 0; i < my_strlen(str); i++){
        if(str[i] == '%' ||str[i] == '/' || str[i] == '*' || str[i] == '-' || str[i] == '+') {
            count++;
            if(count > 2) return 1;
        }
        else count = 0;
    }
    return 0;
}

short space(char* str) {
    for(short i = 0; i < my_strlen(str); i++) {
        if(str[i] == ' ') return 1;
    }
    return 0;
}

short check_divide_error(char* str) {
    for(int i = 0; i < my_strlen(str); i++) {
        if(str[i] == '/' && str[i + 1] == '0') return 1; 
    }
    return 0;
}

short char_error(char* str) {
    for(short i = 0; i < my_strlen(str); i++) {
        if(str[i] >= 65 && str[i] <= 90) return 1;
        else if(str[i] >= 97 && str[i] <= 122) return 1;
    }
    return 0;
}

short minus(char* str, short ind) {
    short i = ind - 1, j=0;
    while(i >= 0) {
        if(my_isdigit(str[i]) == 1) break;
        if(str[i] != ')' && str[i] != '(') j++;
        i--;
    }
    return j;
}
