#include <stdio.h>
#include <stdlib.h>

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"

#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 

#define PRINTBIN(x) printf(BYTETOBINARYPATTERN, BYTETOBINARY(x));

void setlsbs(unsigned char *p, unsigned char b0);
unsigned char getlsbs(unsigned char *p);

void setlsbs(unsigned char* p, unsigned char b_0)
{
    int i, y;
    for (i = 0; i < 8; i++)
    {
        int x = b_0 & 1;
        // If x is one set the low order bit to 1 using or
        if (x)
        {
            p[i] |= x;
        }
        // If the value is a 0 and with one's complement to set lo to 0
        else
        {
           p[i] &= ~1; 
        }
        // shift our bit to the right to get the next value in the bit
        b_0 >> 1;
    }
}

int main()
{
    unsigned char p[] = {'5', '1', '3', '5', '7', '9', '2', '4'};
    unsigned char a = '6';
    setlsbs(p, a);
}
