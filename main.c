#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.c"
#include "action.c"

int main(int args, char* argv[]) {
    FILE* file = fopen(argv[1], "r");
    if(args < 2 || file == NULL) {
        printf("Invalid file name\n");
        return 1;
    }
    char* text = read(file);
    actions(text);
    return 0;
}