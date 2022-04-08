#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* first(char* from, unsigned long num);

typedef struct {
    int* actions;
    char* name;
} function;
typedef struct {
    char* name;
    void* value;
    char t;
} variable;

int actions(char* acts) {
    char* tok = strtok(acts, "\n");
    int i1 = 0;
    while(tok != NULL) {
        if(strlen(tok) >= 4) {
            char* key[] = {"SAY ", "SET "};
            int* eq = malloc(8);
            eq[0] = 1;
            eq[1] = 1;
            char* mem = first(tok, 4);
            for(int i = 0; i < 4; i++) {
                if(key[0][i] != toupper(tok[i]))
                    *eq = 0;
                if(key[0][i] != toupper(tok[i]))
                    *(eq + 1) = 0;
            }
            if(eq[0]) {
                for(int i = 4; i < strlen(tok); i++) {
                    char* c = malloc(1);
                    *c = tok[i];
                    if(i == strlen(tok) - 1) {
                        switch(*c) {
                            case '.':
                            case '!':
                            case '?':
                                break;
                            default:
                                printf("%c", *c);
                        }
                    }
                    else
                        printf("%c", *c);
                }
                printf("\n");
            }
            if(eq[1]) {
                variable var;
                char* name = tok + 4;
                name = strtok(name, " ");
                printf("%s\n%s\n%d\n", name, tok, i1);
            }
        }
        printf("%s\n", tok);
        tok = strtok(NULL, "\n");
        i1++;
    }
    return 0;
}

char* first(char* from, unsigned long num) {
    char* res = malloc(num + 1);
    for(unsigned long i = 0; i < num; i++) {
        res[i] = from[i];
    }
    res[num] = '\0';
    return res;
}