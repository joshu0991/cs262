#include <stdio.h>
#include <stdlib.h>

#define RNG_SEED 1467
#define ARRAY_SIZE 25

void randperm (int* a, const int n);
void initilizeArray(int* numArray);
void printArray (int* numArray);

void randperm (int* a, const int n)
{
    int i, temp;
    long rand_number;
    for (i = n - 1; i > 0; i--)
    {
        rand_number = random() % (n);
        temp = a[i];
        a[i] = a[rand_number];
        a[rand_number] = temp;
    }
}

void initilizeArray(int* numArray)
{
    int i;
    for (i =0; i < ARRAY_SIZE; i++)
    {
        numArray[i] = i;
    }
}

void printArray (int* numArray)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf ("%d ", numArray[i]);
    }
    // So the next time we print it starts on a newline
    printf ("\n");   
}

int main()
{
    int numArray[ARRAY_SIZE];
    printf ("Good day, My name is Joshua Lilly. \n"
            "My lab section is 204\n"
            "This program will shuffle an array of ints using Fisher-Yates Shuffle\n");
    srandom (RNG_SEED);
    initilizeArray(numArray);
    int i;
    for (i = 0; i < 1; i++)
    {
        printArray (numArray);
        randperm (numArray, ARRAY_SIZE);
        printArray (numArray);
    }
    return 0;
}
