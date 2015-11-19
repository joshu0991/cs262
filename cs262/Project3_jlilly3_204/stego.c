/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
 * Stego.c: A program for manipulating images                           *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <string.h>
#include "image.h"

int main(int argc, char *argv[])
{  
  int i, j, k, cover_bits, bits;
  struct Buffer b = {NULL, 0, 0};
  struct Image img = {0, NULL, NULL, NULL, NULL, 0, 0};
  char *s;
  byte b0;
   
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

  // embed two size bytes
  // 
  //

  // embed 4 file extension characters (to make it easy for the extraction)
  // 
  //
  //
	   
  for (i=0; i<b.size; i++)
    {
      // here you embed information into the image one byte at the time
      // note that you should change only the least significant bits of the image
     

    }

  WriteImage(argv[2],img);  // output stego file (cover_file + file_to_hide)
}
