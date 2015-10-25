#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc != 2)
        exit(1);

    FILE* outfile;
    outfile = fopen(argv[1], "w");
    if (!outfile)
        exit(1);
    char buffer[] = "whoopie!";
    fprintf(outfile, "%s", buffer);
    fclose(outfile);
    return 0;
}
