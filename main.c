#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.c"

int main(int args, char* argv[]) {
    FILE* file = fopen("main.kln", "r");
    if(file == NULL) {
        printf("Invalid File Name\n");
        return 1;
    }
    char* text = read(file);
    return 0;
}