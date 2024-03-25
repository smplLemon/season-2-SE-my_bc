#include "../h/check_function.h"
#include "../h/my_string.h"

short operator(char op) {
    if(op == '(')  return 0;
    if(op == '-' || op == '+') return 1;
    if(op == '/' || op == '*') return 2;
    return -1;
}

short check(char c) {
    short flag = 1;
    if(c == '0') flag = 0;
    if(c == '1') flag = 0;
    if(c == '2') flag = 0;
    if(c == '3') flag = 0;
    if(c == '4') flag = 0;
    if(c == '5') flag = 0;
    if(c == '6') flag = 0;
    if(c == '7') flag = 0;
    if(c == '8') flag = 0;
    if(c == '9') flag = 0;
    if(c == '+') flag = 0;
    if(c == '-') flag = 0;
    if(c == '/') flag = 0;
    if(c == '*') flag = 0;
    if(c == '%') flag = 0;
    if(c == '(') flag = 0;
    if(c == ')') flag = 0;
    if(c == ' ') flag = 0;
    return flag;
}

short check_minus(char* str, short ind) {
    short index = 0;
    for(short i = ind - 1; i >= 0; i--) {
        if(my_isdigit(str[i]) == 1) break;
        if(str[i] != ')' && str[i] != '(') index++;
    }
    return index;
}
