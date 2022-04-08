/* A C program to demonstrate working of memcpy */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void actions(char* acts);
int main ()
{
	actions("TestingStuff");
	return 0;
}
void actions(char* acts) {
	char* tok = strtok(acts, "\n");
	char* mem = malloc(1);
	printf("%s\n", mem);
}