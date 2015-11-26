/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
 * Stego.c: A program for manipulating images                           *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <string.h>
#include "image.h"
#include "Lab11_jlilly3_204.h"

int main(int argc, char *argv[])
{  
  int i, j, k, cover_bits, bits;
  struct Buffer b = {NULL, 0, 0};
  struct Image img = {0, NULL, NULL, NULL, NULL, 0, 0};
  char *s;
   
  if (argc != 4) 
    {
      printf("\n%s <cover_file> <stego_file> <file_to_hide> \n", argv[0]);
      exit(1);
    }
  ReadImage(argv[1],&img);       // read image file into the image buffer img
                                 // the image is an array of unsigned chars (bytes) of NofR rows
                                 // NofC columns, it should be accessed using provided macros
  ReadBinaryFile(argv[3],&b);    // Read binary data
 
  s = strchr(argv[3],(int)'.');
  if (strlen(s)!=4) s = ".txt";
  printf("hidden file type = <%s>\n",s+1);

  // hidden information 
  // first two bytes is the size of the hidden file
  // next 4 bytes is the extension (3 letters & \0)
  if (!GetColor)
    cover_bits = img.NofC*img.NofR;
  else 
    cover_bits = 3*img.NofC*img.NofR;    
  bits = (6+b.size)*8;
  if (bits > cover_bits)
    {
      printf("Cover file is not large enough %d (bits) > %d (cover_bits)\n",bits,cover_bits);
      exit(1);
    }
  
  // embed four size bytes
  int a, last_stop = 0;
  unsigned int size = b.size;
  printf("Size is %u\n", size);
  for (a = 3; a >= 0; a--)
  {
    // Write the high order bytes out first for
    // easy extraction.
    byte b = (size >> 8 * a) & 0xFF;
    int m;
    // Fill the buffer with enough bits to write out the lower 8 bits of an int
    unsigned char buffer[8];
    for (i = 0, m = last_stop; i < 8; m++, i++)
    {
      buffer[i] = GetGray(m);
    }
    last_stop = m;
    setlsbs(buffer, b);

    int l;
    for (i = 0, l = (last_stop - 8); i < 8; l++, i++)
    {
      SetGray(l, buffer[i]);
    } 
  }

  // embed g num  into the file each digit gets 4 bits
  // My g num = 00561467 = 0x00, 0x38, 0x0E, 0x43
  byte gNum[5] = {0x00, 0x00, 0x38, 0x0E, 0x43}; 
  for (a = 0; a < 5; a++)
  {
    unsigned char buffer[8];
    for (i = 0, j = last_stop; i < 8; j++, i++) 
    { 
      buffer[i] = GetGray(j);
    }
    last_stop = j;
    setlsbs(buffer, gNum[a]);

    int l;
    for (i = 0, l = (last_stop - 8); i < 8; l++, i++)
    {
      SetGray(l, buffer[i]);
    } 
  }
  
  // Write out the image
  for (i=0; i < b.size; i++)
    {
      // here you embed information into the image one byte at the time
      byte toInsert = GetByte(i);;
      byte buffer[8];
      for (j = 0, k = last_stop; j < 8; j++, k++)
      {     
        buffer[j] = GetGray(k);
      }         
      last_stop = k;
      setlsbs(buffer, toInsert);
//if (i == 0 || i == 2)
//{
//printf("Buffer Is \n"); 
//print_bin(buffer);
//}
      int l, q;
      for (q = 0, l = (last_stop - 8); q < 8; l++, q++)
      {
        SetGray(l, buffer[q]);
      } 
    }
 
  WriteImage(argv[2],img);  // output stego file (cover_file + file_to_hide)*/
  return 0;
}
