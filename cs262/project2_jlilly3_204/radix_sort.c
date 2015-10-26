#include "link.h"

int main(int argc, char** argv)
{
    ListNode** head_pointers;
    ListNode* main_head;
    main_head = newList();

    int total_size = 0;
    if (argc != 5)
        return 1;

    // Init the list and the head pointers
    head_pointers = malloc(10 * sizeof(ListNode));
    int i;
    for (i = 0; i < 10; i++)
    {
        head_pointers[i] = newList();
    }


    int seed = atoi(argv[1]);
    int N = atoi(argv[2]);
    int min = atoi(argv[3]);
    int max = atoi(argv[4]);

    int temp = atoi(argv[4]);
    while (temp)
    {
        temp /= 10;
        total_size++;
    }

    // Seed random
    srand(seed);

    // build a randomized list
    int m;
    for (m = 0; m < N; m++)
    {
        int num = (rand() % (max+1-min))+min;
        int* c_rep = getCharRep(num, total_size);
        insert(main_head, num, c_rep);        
    }
    printList(main_head);

    // Clean up all of the head nodes.
    int j;
    for (j = 0; j <10; j++)
    {
        delete_entire_list(head_pointers[j]);
    }

    free(head_pointers);
    return 0;
}
