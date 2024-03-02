#include "../h/my_string.h"

char** my_split(char* content) {
    short i = 0, j = 1, ind = 1, size = 3;
    for( ; content[i]; i++) {
        if(content[i] == '\n') size++;
    }
    char** arr = (char**)malloc(sizeof(char*)*(size + 1));
    arr[size] = NULL;
    for(size = 0; content[size] != '\n'; size++);
    for(i = 0; arr[i]; i++) {
        arr[i] = (char*)calloc(sizeof(char), size+5);
    }
    for(i = 0; content[i]; i++) {
        if(content[i] != '\n') {
            arr[ind][j++] = content[i];
        } else {
            ind++;
            j = 1;
        }
    }
    return arr;
}
