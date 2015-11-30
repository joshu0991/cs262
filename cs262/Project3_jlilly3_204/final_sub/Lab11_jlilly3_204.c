// Joshua Lilly, G00561467
// Lab section 204
// Nov. 15

#include "Lab11_jlilly3_204.h"

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

//! Set the least significant bit for all values in an array to the coorrisponding bit pos. in b_o
void setlsbs(unsigned char* p, unsigned char b_0)
{
    int i;
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
        b_0 = b_0 >> 1;
    }
}

//! Get the least significant bit from each position in an array and add it to a byte
unsigned char getlsbs(unsigned char *p)
{
    int i;
    unsigned char c = 0;
    for (i = 0; i < 8; i++)
    {
        // find out what the lsb is
        int x = p[i] & 1;
        if (x)
        {
            // if the lsb was a one insert a one and shift it into position
            c |= 1 << i;
        }
    }
    return c;
}

//! Print a given array in decimal 
void print_decimal(unsigned char* p)
{
    int k;
    for (k = 0; k < 8; k++)
    {
        printf("Num at %d: %d\n", k, p[k]);
    }
}

//! Print a given array in in bianary representation
void print_bin(unsigned char* p)
{
    int c;
    for (c = 0; c < 8; c++)
    {
        printf("Num at %d ", c);
        PRINTBIN(p[c]);
        printf("\n");
    } 
}
