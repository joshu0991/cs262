#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char* slloc_copy(char* str);

int main()
{
    char buffer[] = "hello stack string";
    char* s;
    s = slloc_copy(buffer);
    printf("%s\n", s);
    free (s);
}

char* slloc_copy(char* str)
{
    char* space = malloc ((strlen(str) + 1) * sizeof(char));
    if (space)
        strcpy(space, str);
    return space;
}
