#include <stdio.h>

void skeeve()
{
    char s[] = "this_is_a_long_string";
    char* p = s;
    while (*(p++))
    {
        if (*p == '_')
            *p = '\0';
    }
    printf("%s\n", s);
}


int main()
{
    skeeve();
}
