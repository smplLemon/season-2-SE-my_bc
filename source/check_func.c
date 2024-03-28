#include "my_string.h"

short parse_error(char* string) {
    for(short i = 0; i < my_strlen(string); i++) {
        if(string[i] == '(' && string[i + 1] == ')') return 1;
    }
    return 0;
}

short check(char* string) {
    short count = 0;
    for(short i = 0; i < my_strlen(string); i++) {
        if(string[i] == '%' ||string[i] == '/' || string[i] == '*' || string[i] == '-' || string[i] == '+') {
            count++;
            if(count > 2) return 1;
        }
        else count = 0;
    }
    return 0;
}

short check_space(char* string) {
    for(short i = 0; i < my_strlen(string); i++) {
        if(string[i] == ' ') return 1;
    }
    return 0;
}

short divide_error(char* string) {
    for(short i = 0; i < my_strlen(string); i++) {
        if(string[i] == '/' && string[i + 1] == '0') return 1; 
    }
    return 0;
}

short charector_error(char* string) {
    for(short i = 0; i < my_strlen(string); i++) {
        if(string[i] >= 65 && string[i] <= 90) return 1;
        else if(string[i] >= 97 && string[i] <= 122) return 1;
    }
    return 0;
}

short check_minus(char* string, short index) {
    short i = index - 1, j;
    for(j=0; i >= 0; i--) {
        if(my_isdigit(string[i]) == 1) break;
        if(string[i] != ')' && string[i] != '(') j++;
    }
    return j;
}
