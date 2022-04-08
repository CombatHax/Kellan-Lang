#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* first(char* from, unsigned long num);

int actions(char* acts) {
    char* tok = strtok(acts, "\n");
    while(tok != NULL) {
        if(strlen(tok) >= 4) {
            char* key = "SAY ";
            int* eq = malloc(4);
            *eq = 1;
            char* mem = first(tok, 4);
            for(int i = 0; i < 4; i++) {
                if(key[i] != toupper(tok[i]))
                    *eq = 0;
            }
            if(*eq) {
                for(int i = 4; i < strlen(tok); i++) {
                    char* c = malloc(1);
                    *c = tok[i];
                    if(i >= strlen(tok) - 1) {
                        switch(*c) {
                            case '.':
                            case '!':
                            case '?':
                                break;
                            default:
                                printf("%c", *c);
                        }
                    }
                    else {
                        printf("%c", *c);
                    }
                }
                printf("\n");
            }
        }
        tok = strtok(NULL, "\n");
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