#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int* actions;
    char* name;
} function;
typedef struct {
    char* name;
    void* value;
    char t;
} variable;

char* read(FILE* f) {
    variable* vars = malloc(1);
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