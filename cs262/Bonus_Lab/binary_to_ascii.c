#include "common.h"

int main(int argc, char** argv)
{
    if (argc != 3)
        return 1;

    FILE* in_bin = fopen(argv[2], "rb");
    FILE* out_ascii = fopen(argv[3], "w");
    FileData record;

    if (!in_bin || !out_ascii)
        return 1;

    size_t nread;
    while ((nread = fread(&record, sizeof(FileData), 1, in_bin)) > 0) 
    {
        fwrite(&record, sizeof(FileData), 1, out_ascii);
    }
    fclose(in_bin);
    fclose(out_ascii);
    return 0;
}
