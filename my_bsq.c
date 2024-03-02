#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "./h/my_string.h"
#include "./h/map.h"

short content_check(char* str) {
    short line1 = 0, line2 = 0, i, flag;
    for(i = 0; str[i]; i++) {
        flag = 0;
        if(str[i] != '.' && str[i] != 'o' && str[i] != '\n') {
            flag = 1;
        }
        if(flag == 1) {
            return 1;
        }
    }
    for(i = 0; str[i]; i++) {
        line1++;
        if(str[i] == '\n') {
            if(line2 != 0 && line1 != 0 && line1 != line2) {
                return 1;
            }
            line2 = line1;
            line1 = 0;
        }
    }
    return 0;
}

short error(short flag) {
    if(flag == 0) printf("no such file\n");
    if(flag == 1) printf("wrong map\n");
    return 1;
}

int main(int ac, char** av) {
    if(ac == 1) return error(0);
    short fd = open(av[1], O_RDONLY);
    if(fd == -1) return error(0);
    struct stat file_stat;
    stat(av[1], &file_stat);
    short size = (short)file_stat.st_size;
    if(size == 0) {
        close(fd);
        return error(1);
    }
    char* content = (char*)calloc(sizeof(char), size + 1);
    read(fd, content, size);
    if(content_check(content) == 1) {
        free(content);
        return error(1);
    }
    char** arr = my_split(content);
    arr = square(arr);
    for(size = 1; arr[size]; size++) {
        if(arr[size][1]) {
            printf("%s\n", &arr[size][1]);
        }
    }
    for(size = 0; arr[size]; size++) {free(arr[size]);}
    free(arr);
    free(content);
    close(fd);
    return 0;
}
