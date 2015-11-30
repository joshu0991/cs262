#include "common.h"

// Read in ascii and write out bianary data
int main(int argc, char** argv)
{
    // Error out silently
    if (argc != 3)
        return 1;

    // The ascii file from input
    FILE* in_file = fopen(argv[1], "r");
    FILE* bin_write = fopen(argv[2], "wb");
    FileData record;

    // Error 
    if (!in_file || !bin_write)
        return 1;

    size_t nread;
    while ((nread = fread(&record, sizeof(FileData), 1, in_file)) > 0)
    {
        fwrite(&record, sizeof(FileData), 1, bin_write);
    }
    fclose(in_file);
    fclose(bin_write);
    return 0;
}
