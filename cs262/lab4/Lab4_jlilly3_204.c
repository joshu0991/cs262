#include <stdio.h>
#include <stdlib.h>

#define RNG_SEED 1467
#define ARRAY_SIZE 25

void shuffleArray (int* a, const int n);
void initilizeArray(int* numArray, const int);
void printArray (int* numArray);

/*! Permute a random array
 *  param[in] int* a pointer to our array
 *  param[in] const int n the size of our array
 */
void shuffleArray (int* a, const int n)
{
    int i, temp;
    long rand_number;
    // Go from the top down to i = 1
    for (i = n - 1; i > 0; i--)
    {
        // Generate random numbers 0 - 24 (array indecies
        rand_number = random() % (n);
        // Swap array values
        temp = a[i];
        a[i] = a[rand_number];
        a[rand_number] = temp;
    }
}

/*!
 * Init the given array with counting numbers
 * param[in] int* numArray the array we will populate
 */
void initilizeArray(int* numArray, const int length)
{
    // Populate from zero up to array size 0 - 24
    int i;
    for (i =0; i < length; i++)
    {
        numArray[i] = i;
    }
}

/*!
 * print the given array
 * param[in] int* numArray the array to print
 */
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
    int i;
    for (i = 0; i < 10; i++)
    {
        initilizeArray(numArray, ARRAY_SIZE);
        printArray (numArray);
        shuffleArray (numArray, ARRAY_SIZE);
        printArray (numArray);
    }
    return 0;
}
