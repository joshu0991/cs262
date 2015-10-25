// Joshua Lilly G00561467
// CS 262, Project I Lab section 204
// September 21, 2015

#include <stdio.h>
#include <stdlib.h>

typedef enum bool
{
    FALSE,
    TRUE
} bool;


bool encryptf(const char* key, const char* in_file_name, const char* out_file_name);

/*!
    Funtion to encript/decrypt an input file and output the contents to the output file
    param[in] key the key we will use to encrypt out file
    param[in] in_file_name a const char pointer to our file name
    param[in] out_file_name a const char pointer to our output file name
    \return true on success false on failure.
*/
bool encryptf(const char* key, const char* in_file_name, const char* out_file_name)
{
    FILE* out_file;
    FILE* in_file;

    // Convert our key to an int
    int kasi = atoi(key); 

    // Open our files for read/write
    out_file = fopen(out_file_name, "w");
    in_file = fopen(in_file_name, "r");

    // check to see if files opened
    if (!out_file)
        return FALSE;
    if (!in_file)
       return FALSE;
 
    // Seed rng
    srand(kasi); 
    
    // Encryption/decryption vars
    int r = 0;
    char p, p1, c, c1;
    
    // While we are not at the end of a file read a character
    while((p = fgetc(in_file)) != -1)
    {
        // Gen a random number
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
       
        // bitwise xor
        c1 = p1 ^ r;
      
        if (c1 == '0')
        {
            c = '\t';
        }
        else if (c1 == '1')
        {
            c = '\n';
        }
        else
        {
            c = c1 + 30;
        }
        // Write the new char to the file
        fputc(c, out_file); 
    }
    // This is c we clean up after ourselves
    fclose (out_file);
    fclose (in_file);
    return TRUE;
}

int main(int argc, char** argv)
{
    // 4 since program name key infile outfile for successful input
    if (argc == 4)
    {
        // We will track if the function call was a success.
        bool success = encryptf(argv[1], argv[2], argv[3]);
        if (success)
        {
            printf("encryption/decription successful\n");
            return 0;
        }
        return 1;
    }
    // The unix style of handling improper input is not to throw exceptions
    // but to silently ignore stupid input so that is what we will do here as well.
    return 1;
}
