// Joshua Lilly, G00561467
// Lab section, 204
// September 29, 2015

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum boolean 
{
    FALSE,
    TRUE
}bool;

bool copy (const char* infile, const char* outfile);

bool copy (const char* infile, const char* outfile)
{
    FILE* in;
    FILE* out;
    char buffer[100];

    in = fopen(infile, "r");
    assert (in != NULL);
    if (!in)
    {
        return FALSE;
    }

    out = fopen(outfile, "w");
    assert (out != NULL);
    if (!out)
    {
        return FALSE;
    }

    while(1)
    {
       if (fgets (buffer, 100, in) == NULL) break;
       fputs (buffer, out);

#ifndef NDEBUG
       printf ("%s", buffer);
#endif

    }
    fclose (in);
    fclose (out);
    return TRUE;
}

int main (int argc, char** argv)
{
    // Make sure we have the correct number of arguments
    if (argc != 3 )
        exit(1);

    bool success = copy (argv[1], argv[2]);

    if (success)
    {
        return 0;
    }
    printf ("Failed to copy file due to an error \n");
    return 1;
}
