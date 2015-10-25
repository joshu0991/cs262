#include <stdio.h>

void crunk(int*, int*);

int main()
{

   int i = 5, j = 20;
   crunk(&i, &j);
   printf("%d, %d\n", i, j);
}

void crunk(int* p, int* q)
{
    *q = *p;
    *p = 17;
}
