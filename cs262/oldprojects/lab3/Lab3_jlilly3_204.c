// Joshua Lilly G00561467
// CS 262, Lab Section 204
// Lab 3

#include <stdio.h>

void print_menu();
char enter_char();
int enter_triangle_size();
void print_right(char, int);
void print_left(char, int);

/*!
 *  This function will print the main user menu  
 */
void print_menu()
{
    printf("Change character enter C or c\n");
    printf("Change number enter N or n\n");
    printf("Print triangle type 1 (Left Justified) enter 1\n");
    printf("Print triangle type 2 (Right justified) enter2\n");
    printf("Quit program Q or q\n");
    printf("->\n");
}

/*!
 *  This function gets a character from the user
 */
char enter_char()
{
    char character;
    printf("Enter a single character\n");
    scanf(" %c", &character); 
    return character;      
}

/*!
 *  This function sets the triangle size and ensures the value is in the bounds.
 */
int enter_triangle_size()
{
    int tri_size = 0;
    while( tri_size <= 0 || tri_size > 15)
    {
        printf("Enter the size of the triangle to print (1 - 15)\n");
        scanf("%d", &tri_size);
    }
    return tri_size;
}

/*!
 *  This function prints a right aligned triangle
 */
void print_right(char c, int size)
{
    int i, j;
    for(i = 1; i <= size; ++i)
    {
        for(j = size; j > 0; --j)
        {
            if (j > i)
            {
                printf(" ");
            }
            else
            {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}

/*!
 *  This function prints a left aligned triangle.
 */
void print_left(char c, int size)
{
    int i, j;
    for(i = 0; i < size; ++i)
    {
        for(j = 0; j < size; ++j)
        {
            if (j <= i)
            {
                printf("%c", c);
            }
        }
        printf("\n");
    }

}

int main()
{
    char option = ' ';
    char C = ' ';
    short control = 1;
    int N = 0;

    while(control)
    {
        print_menu();
        scanf(" %c", &option);
        switch (option)
        {
            case 'c':
            case 'C':
                C = enter_char();
                break;
            
            case 'q':
            case 'Q':
                control = 0;
                break;

            case 'n':
            case 'N':
                N = enter_triangle_size();
                break;

            case '1':
                print_left(C, N);
                break;

            case '2':
               print_right(C, N); 
               break;

            default:
                printf("Invalid operation");
        }
    } 
    return 0;
}
