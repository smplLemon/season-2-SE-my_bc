short my_pow(short num, short pw) {
    short ret = 1;
    while(pw > 0) {
        ret *= num;
        pw--;
    }
    return ret;
}

short my_strlen(char* string) {
    short len = 0;
    while(string[len] != '\0')  len++;
    return len;
}

short char_to_decimal(char* string) {
    short  num = 0;
    short i = 0;
    short  ind = my_pow(10, my_strlen(string)) / 10;
    while(string[i]) {
        num += (string[i] - 48) * ind;
        i++;
        ind /= 10;
    }
    return num;
}

void un_space(char* string) {
    short length = my_strlen(string);
    for(int i = 0; i < length; i++){
        if(string[i] == ' '){
            short j = i;
            while(j < length){
                string[j] = string[j + 1];
                j++;
            }
            i = 0;
            length--;
        }
    }
    string[length] = '\0';
}

char* my_strcpy(char *string1, char *string2) {
    for(int i = 0; string2[i]; i++) string1[i] = string2[i];
    return string1;
}

void my_strncpy(char *dest, char *source, int size)
{
    for(int i = 0; i < size; i++)
        dest[i] = source[i];
}

void fill_with_null(char *string, int size)
{
    for(int i = 0; i < size; i++)
        string[i] = '\0';
}

int my_strcmp(char* str1, char* str2) {
    for( ; *str1 || *str2; str1++, str2++) {
        if(*str1 != *str2) {
            return ((*str1) - (*str2));
        }
    }
    return 0;
}

short my_isdigit(char c) {
    if(c >= 48 && c <= 57) return 1;
    return 0;
}