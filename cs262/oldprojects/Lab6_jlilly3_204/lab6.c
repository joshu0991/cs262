//  CS262  Lab 6
//
//  Name:  ________________________________
//  Lab Section: _____________
//
// This program calculates the sum of the integers from
// 0 up to (and including) an integer input by the user
#include <stdio.h>
#include <stdlib.h>

int main()
{
//  int i, count
    int i, count;
//  int sum = 0;
    int sum;
    printf("Enter an integer -> ");
//  scanf("%d", count);
    scanf("%d", &count);
//  for (i == 0; i < count; i++);
//  for (i = 0; i < count; i++);
//  for (i = 0; i < count; i++)
    for (i = 0; i <= count; i++)
    {
        sum += i;
        printf("i = %d sum = %d\n", i, sum); // Added for Debugging
    }
    printf("The sum of integers 0 to %d is: %d\n", count, sum);
    return 0;
}
