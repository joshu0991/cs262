#include <stdio.h>
#include <stdlib.h>

typedef enum bool
{
    FALSE,
    TRUE
} bool;

// Return true on success false on failure.
bool encryptf(const char* key, const char* in_file_name, const char* out_file_name)
{
    FILE* out_file;
    FILE* in_file;

    int kasi = atoi(key); 
    out_file = fopen(out_file_name, "a+");
    in_file = fopen(in_file_name, "a+");
    // check to see if files opened

    printf("out %s\n", out_file_name);
    printf("%s\n", in_file_name);
    printf("%d\n", kasi);
    srand(kasi); 
    int r = 0;
    //r = rand() % 97;
    char p, p1, c, c1;
    while((p = fgetc(in_file)) != EOF)
    {
        printf("the char value is %c\n", p); 
    r = rand() % 97;
        if (p == '\t')
        {
            p1 = '0';
        }
        else if (p == '\n')
        {
            p1 = '1';
        }
        else
        {
            p1 = p - 30;
        }

       printf(" p1 is %c\n", p1);
       
        c1 = p1 ^ r;
     printf("c1 is %c\n", c1);
        if (c1 == 0)
        {
            c = '\t';
        }
        else if (c1 == 1)
        {
            c = '\n';
        }
        else
        {
            c = c1 + 30;
        }
        printf("----------%c\n", c);    
        fputc(c, out_file); 
    }
    fclose (out_file);
    fclose (in_file);
    return TRUE;
}

int main(int argc, char** argv)
{
    int i;
    if (argc == 4)
    encryptf(argv[1], argv[2], argv[3]);
}
