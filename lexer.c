#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int* actions;
    int* locs;
} actions;
typedef struct {
    int* actions;
    char* name;
} function;

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
    char* tok = strtok(acts, "\n");
    char* mem = malloc(4);
    for(int i = 0; tok != NULL; i++) {
        memcpy(mem, tok, 4);
        if(!(strcmp(mem, "prt "))) {
            if(sizeof(tok) < 5) {
                printf("Problemo");
                tok = strtok(NULL, "\n");
                continue;
            }
            char* val = malloc(sizeof(tok) - 4);
            strcpy(val, tok + 4);
            printf("%s\n", val);
        }
        tok = strtok(NULL, "\n");
    }
    return acts;
}