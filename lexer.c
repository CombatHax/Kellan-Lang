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
    char* tok = strtok(acts, "\n");
    char* mem = malloc(4);
    for(int i = 0; tok != NULL; i++) {
        memcpy(mem, tok, 6);
        if(!(strcmp(mem, "write "))) {
            char* val = malloc(sizeof(tok) - 6);
            strcpy(val, tok + 6);
            printf("%s\n", val);
            free(val);
        }
        else if(strchr(tok, '=') != NULL) {
            char* c = strchr(tok, '=');
            unsigned long in = (unsigned long)(c - tok);
            char* name = strtok(tok, "=");
            if(name[sizeof(name) - 2] == ' ') {
                name[sizeof(name) - 2] = '\0';
            }
            printf("%s\n", name);
        }
        tok = strtok(NULL, "\n");
    }
    return acts;
}