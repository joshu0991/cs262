                                                                                          
#include <string.h>                                                                       
#include "image.h"                                                                        
#include "Lab11_jlilly3_204.h"                                                            
                                 
int main(int argc, char *argv[])                                                          
{                                                                                         
    int i, j, k, last_index = 0;                                                          
    struct Image img = {0, NULL, NULL, NULL, NULL, 0, 0};                                   
    
    if (argc != 3)                                                                          
    {                                                                                     
         printf("\n%s <cover_file> <out_file> \n", argv[0]);                
         exit(1);                                                                            
    }

    ReadImage(argv[1],&img);

    // Extract the file size which is the first 32 bytes of the cover file
    unsigned int size = 0;
    for (i = 0; i < 4; i++)
    {
        // Fill th buffer
        byte buffer[8];
        for (j = 0, k = last_index; j < 8; j++, k++)
        {
            buffer[j] = GetGray(k);
        }
        last_index = k;
        size = size << 8;
        byte data = getlsbs(buffer);
        size |= data;
    }
    printf("The size of the file was %u\n", size);

    // init b
    struct Buffer b = {NULL, 0, 0};
    b.data = (byte *)malloc(sizeof(byte)*size + 1);
    b.size = size;
    b.max_size = size + 1;
 
    // extract the g num
    unsigned int gNum[5];
    for (i = 0; i < 5; i++)
    {
        byte buffer[8];
        for (j = 0, k = last_index; j < 8; j++, k++)
        {
            buffer[j] = GetGray(k);
        }
        last_index = k;
        byte data = getlsbs(buffer);
        gNum[i] = data;
    }
    printf("The G number is: G%u%u%u%u%u\n", gNum[0], gNum[1], gNum[2], gNum[3], gNum[4]);

    // Extract the entire image
    for (i = 0; i < size; i++)
    {
        byte buffer[8];
        for (j = 0, k = last_index; j < 8; j++, k++)
        {
            buffer[j] = GetGray(k);
        }
        last_index = k;
        byte data = getlsbs(buffer);
if(i ==0)
{
print_bin(buffer);        
}
        SetByte(i, data);
    }
    WriteBinaryFile(argv[2], b);
    return 0;
} 
