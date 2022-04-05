#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* read(FILE* f) {
    char* acts = malloc(1);
    char c = fgetc(f);
    unsigned long row = 0;
    short quotes = 0;
    int spaces = 0;
    while(c != EOF) {
        row++;
        if(c == '"') 
            quotes = !(quotes % 2) ? 1 : 0;
        if(c == ' ' && !quotes) {
            if(spaces == 3) {
                printf("Tab");
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
    printf("%s", acts);
    return acts;
}