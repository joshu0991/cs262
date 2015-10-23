// Joshua Lilly
// G00561467
// CS 262, Lab 204
// 10/22/2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! Our location struct for storing locations
struct location
{
    char loc_name[35];
    char description[85];
    float latitude;
    float longitude;
};

void runMenu();
void add_location(struct location** p_location_array, int* p_array_size, int* p_current_size);
void resize_array(struct location** p_location_array, int* p_array_size);
void print (struct location* p_array, int p_current_size);

// Print out the main menu to the user.
void runMenu()
{
    printf("[A]dd additional Locations\n");
    printf("[P]rint the current list of locations\n");\
    printf("[Q]uit the program\n");
}

//! Resize the array to two times it's origional size.
void resize_array(struct location** p_location_array, int* p_array_size)
{
    // Allocate enough space for two times the size of the array
    int new_size = 2 * (*p_array_size);
    struct location* new_location_array = malloc(new_size * sizeof(struct location));
    if (!new_location_array)
    {
        printf ("Cannot add more elements heap has exhausted all space\n");
        exit(1);
    }
    // Copy the old array to the new array.
    memcpy(new_location_array, *p_location_array, ((*p_array_size ) * sizeof(struct location)));
    // We will update the current size of the array for later checking.
    *p_array_size = 2 * (*p_array_size);
    // We have a copy of the old array so we can free it.
    free(*p_location_array);
    // The contents of the pointer reference get the array we malloced in this function
    *p_location_array = new_location_array;
}

//! Add a new location to our array. If the array isn't large enough resize it then insert the new struct.
void add_location(struct location** p_location_array, int* p_array_size, int* p_current_size )
{
    // Get the users input
    struct location new_location;
    printf("Enter the new location name\n ");
    fscanf(stdin, "%s", new_location.loc_name); 
    printf("Enter a description of the location\n");
    fscanf(stdin, "%s", new_location.description),
    printf("Enter the latitude\n");
    fscanf(stdin, "%f", &new_location.latitude);
    printf("Enter the longitude\n");
    fscanf(stdin, "%f", &new_location.longitude);

    // Check to see if the size is correct.
    if (*p_array_size <= *p_current_size)
    {
        // If not the correct size resize the array
        resize_array(p_location_array, p_array_size);
    }
    // Insert our sruct
    (*p_location_array)[*p_current_size] = new_location;
}

//! Loop over and print out the locations
void print (struct location* p_array, int p_current_size)
{
    int i;
    for (i = 0; i < p_current_size; i++)
    {
        struct location current = p_array[i];
        printf("%s :  %s  : %f : %f\n", current.loc_name, current.description, current.latitude, current.longitude);
    } 
}



int main()
{
    char choice = ' ';
    short control = 1;
    int size;
    int currentSize = 0;
 
    printf("Enter the inital size of the array\n");
    scanf(" %d", &size);
 
    // Make a new struct array from the heap
    struct location* m_location_array = 
         malloc(size * sizeof(struct location));

    // Make sure we have a valid chunk of the heap.
    if (!m_location_array)
        exit(1);

    while(control)
    {
        runMenu();
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'a':
            case 'A':
                // Do Add additional
                add_location(&m_location_array, &size, &currentSize);
                currentSize++;
                break;
            case 'p':
            case 'P':
                // Do printing
                print (m_location_array, currentSize);
                break;
            case 'Q':
            case 'q':
                control = 0;
                break;
            default:
                printf("Invalid input\n");
        }   
    }
    // clean up after ourselves.
    free (m_location_array);
    return 0;

}
