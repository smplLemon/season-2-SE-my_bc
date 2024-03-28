short my_strlen(char* str) {
    short len = 0;
    while(str[len] != '\0') len++;
    return len;
}

short decimal(char* str) {
    short  num = 0;
    for(short i = 0; str[i]; i++) {
        num *= 10;
        num += (short)(str[i]-48);
    }
    return num;
}

void free_space(char* str) {
    short length = my_strlen(str);
    for(short i = 0; i < length; i++) {
        if(str[i] == ' ') {
            short j = i;
            while(j < length) {
                str[j] = str[j + 1];
                j++;
            }
            i = 0;
            length--;
        }
    }
    str[length] = '\0';
}

char* my_strcpy(char *str1, char *str2) {
    for(int i = 0; str2[i]; i++) str1[i] = str2[i];
    return str1;
}

void fill_null(char *str, short over) {
    for(int i = 0; i < over; i++) str[i] = '\0';
}

short my_isdigit(char c) {
    if(c >= 48 && c <= 57) return 1;
    return 0;
}
