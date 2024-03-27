#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

short READLINE_READ_SIZE = 6;
char* store;

typedef struct list
{
    short size;
    short count;
    char* text;
} line;

char* my_strcpy(char* str1, char* str2) {
    for(short i = 0; str2[i]; i++) str1[i] = str2[i];
    return str1;
}

short my_strlen(char* str) {
    short len = 0;
    while(str[len] != '\0') len++;
    return len;
}

void fill_null(char* str, short over) {
    for(short i =0; i<=over; i++) str[i] = '\0';
}

char* my_realloc(char* str, short add_size) {
    char* temp = malloc(sizeof(char) * (add_size + 1 + READLINE_READ_SIZE));
    fill_null(temp, (add_size + READLINE_READ_SIZE));
    my_strcpy(temp, str);
    free(str);
    return temp;
}

void to_store(char* after_line) {
    fill_null(store, READLINE_READ_SIZE);
    short i = 0;
    while(after_line[i] != '\0') {
        store[i] = after_line[i];
        i++;
    }
    store[i] = '\0';
}

void init_my_readline() {
    if(store) free(store);
    store = malloc(sizeof(char) * READLINE_READ_SIZE + 1);
    fill_null(store, READLINE_READ_SIZE);  
}

short check_line(line* answer, char* str) {   
    short len = my_strlen(str);
    for(short i = 0; i < len; i++) {
        if(str[i] == '\n') {
            to_store(&str[i + 1]);
            return 1;
        }
        if(answer->size == (READLINE_READ_SIZE) * answer->count) {
            answer->count++;
            answer->text = my_realloc(answer->text, answer->size);
        }
        answer->text[answer->size++] = str[i];
    }
    return 0;
}

char* my_readline(short fd) {
    if(fd != 3 && fd != 0) return NULL;
    line answer;
    answer.count = 1;
    answer.size = 0;
    answer.text = malloc(sizeof(char) * (READLINE_READ_SIZE + 1));
    fill_null(answer.text, READLINE_READ_SIZE);
    char* temp = NULL;
    if(store) {
        temp = malloc(sizeof(char) * (READLINE_READ_SIZE + 1));
        fill_null(temp, READLINE_READ_SIZE);
        my_strcpy(temp, store);
        if(check_line(&answer, temp) == 1) {
            free(temp);
            return answer.text;
        }
    }
    fill_null(temp, READLINE_READ_SIZE);
    while(read(fd, temp, READLINE_READ_SIZE)) {
        if(check_line(&answer, temp) == 1) {
            free(temp);
            return answer.text;
        }
        fill_null(temp, READLINE_READ_SIZE);
    }
    if(answer.text[0]){
        free(temp);
        return answer.text;
    }
    free(temp);
    free(answer.text);
    return NULL;
}

int main(int ac, char** av) {
    char *str= NULL;
    init_my_readline();
    short fd;
    if(ac == 1) fd = 0;
    else fd = open(av[1], O_RDONLY);
    if(ac > 1) {
        while ((str= my_readline(fd)) != NULL) {
            printf("%s\n", str);
            free(str);
        }
    close(fd);
    }
    else {
        str = my_readline(fd);
        printf("%s\n",str);
        free(str);
    }
    return 0;
}
