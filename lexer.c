#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* read(FILE* f) {
    char* acts = malloc(1);
    char c = fgetc(f);
    unsigned long row = 0;
    int spaces = 0;
    while(c != EOF) {
        row++;
        if(c == ' ') {
            if(spaces == 3) {
                spaces = 0;
                c = '\t';
                acts = realloc(acts, row);
                acts[row - 1] = c;
                c = fgetc(f);
                continue;
            }
        }
        acts = realloc(acts, row);
        acts[row - 1] = c;
        c = fgetc(f);
    }
    fclose(f);
    return acts;
}