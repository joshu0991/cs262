// Joshua Lilly G00561467
// // CS 262, Lab Section 204
// // Lab 2

#include <stdio.h>

int main()
{
    double checktotal = 0.0;
    int tipamount = 0;

    printf("Enter the price of your bill\n");
    scanf("%lf", &checktotal);
    printf("Enter the tip amout you would like to leave\n");
    scanf("%d", &tipamount);
    double tipdollar = (( (double) tipamount) / 100) * checktotal; 
    double checkfinaltotal = checktotal + tipdollar;
    printf("Your meal cost: %.2lf\n"
           "Your tip percentage: %d\n"
           "Total tip amount %.2lf\n"
           "Your total cost: %.2lf\n", 
            checktotal, 
            tipamount, 
            tipdollar, 
            checkfinaltotal);
    return 0;
}
