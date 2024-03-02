#include "../h/map.h"
#include "../h/my_string.h"

char** square(char** map) {
    short i, j, ind, len, flag, index;
    int* indexes = (int*)malloc(sizeof(int)*3);
    indexes[0] = 0;
    indexes[1] = 0;
    indexes[2] = 0;
    for(i = 2; map[i]; i++) {
        for(j = 2; map[i][j]; j++) {
            len = 0;
            for(ind = 0; map[i-ind][j] && map[i][j-ind]; ind++) {
                if(map[i][j - ind] != 'o' && map[i - ind][j] != 'o') {
                    flag = 0;
                    for(index = 0; map[i - ind][j -index]; index++) {
                        if(map[i-ind][j-index] == 'o') {
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 0) {
                        len++;
                    }
            }
            if(indexes[2] < len) {
                indexes[0] = i;
                indexes[1] = j;
                indexes[2] = len;
            }
        }
    }
    for(ind = 0; ind < indexes[2]-1; ind++) {
        map[indexes[0] - ind][indexes[1]] = 'x';
        map[indexes[0]][indexes[1]-ind] = 'x';
        for(index = 0; index < indexes[2]-1; index++) {
            map[indexes[0]-ind][indexes[1]-index] = 'x';
        }
    }
    free(indexes); 
    return map;
}
