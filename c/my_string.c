#include "../h/my_string.h"

void fill_null_ind(char* str, short start, short over) {
    for( ; start < over; start++) str[start] = '\0';
}

short my_strlen(char* str) {
    short len = 0;
    for( ; str[len]; len++);
    return len;
}

short char_to_decimal(char* str) {
    short num = 0;
    for(short i = 0; str[i]; i++) {
        num *= 10;
        num += (short)(str[i]-48);
    }
    return num;
}

void free_space(char* str) {
    short len = my_strlen(str), i, j;
    short length = len;
    for(i = 0; i < len; i++) {
        if(str[i] == ' ') {
            for(i=j; j < len; j++)  str[j] = str[j + 1];
            i = 0;
            len--;
        }
    }
    fill_null_ind(str, len, length);
}

char* my_strcpy(char *str1, char *str2) {
    for(short i = 0; i < str2[i]; i++) str1[i] = str2[i];
    return str1;
}

void fill_null(char *str, short over) {
    for(short i = 0; i < over; i++) str[i] = '\0';
}

short my_isdigit(char c) {
    if(c >= 48 && c <= 57)  return 1;
    return 0;
}
