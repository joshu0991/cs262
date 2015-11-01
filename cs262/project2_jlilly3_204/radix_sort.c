//! Joshua Lilly G00561467
//! Project II Radix Sort Linked Lists.
//! October 31, 2015
#include "link.h"

#include <assert.h>

/*! 
 * Sort the linked list using radix sort
 * param[in] p_head_pointers the array of head pointers(buckets)
 * param[in] p_tail_pointers the array of pointers to the tail
 * param[in] p_main_head of the list
 * param[in] p_size the largest size of the number
 */
void radix_sort(ListNode** p_head_pointers, ListNode** p_tail_pointers, ListNode** p_main_head, int p_size);

/*!
 * Stictch together the buckets 
 * param[in] p_head_pointers the pointers to the heads of the list 
 * param[in] p_tails the tails to the lists
 * param[in] p_main_head the main list to stitch the buckets into
 * p_size the size of the largest number
 */
void stitch_together(ListNode** p_heads, ListNode** p_tails, ListNode** p_main_head);

/*!
 * Null the buckets next elements so they no longer point to the nodes.
 * param[in] p_head_pointers the head points (buckets) to empty
 * param[in] p_tail_pointers the tail pointers to empty
 */
void null_out(ListNode** p_head_pointers, ListNode** p_tail_pointers);

//! Sort all of the given integers by the radix.
void radix_sort(ListNode** p_head_pointers, ListNode** p_tail_pointers, ListNode** p_main_head, int p_size)
{
    int i, counter = 1;
    ListNode* curser;
    // This is the main loop responsible for accessing the appropriate positions of the number ie ones tens etc.
    for (i = p_size - 1; i > 0; i--)
    {
        // The curser to move
        curser = (*p_main_head)->next;
        assert(curser != NULL);

        // Sort every number in the list into the appropraite bucket.
        while (curser != NULL)
        {
            // Get the number at the n position
            int position_num = (curser->c_rep)[i];

            // Move the given node to the new position
            move(p_tail_pointers, p_head_pointers, p_main_head, &curser, position_num);

            // Move the curser
            curser = (*p_main_head)->next;
        }
        
        // Stitch together the buckets
        stitch_together(p_head_pointers, p_tail_pointers, p_main_head);       
        printf("The list after %d pass/es is:\n", counter++);
        assert(*p_main_head != NULL);
        printList(*p_main_head);
        
        // We need to empty the buckets.
        assert(p_head_pointers != NULL);
        assert(p_tail_pointers != NULL);
        null_out(p_head_pointers, p_tail_pointers);
    }
}

//! Nulls the buckets
void null_out(ListNode** p_head_pointers, ListNode** p_tail_pointers)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        assert(p_head_pointers[i] != NULL);
        assert(p_tail_pointers[i] != NULL);
        (p_head_pointers[i])->next = NULL;
        (p_tail_pointers[i])->next = NULL;
    }
}

//! Stitch together the number buckets
void stitch_together(ListNode** p_heads, ListNode** p_tails, ListNode** p_main_head)
{
    int i;
    (*p_main_head)->next = (p_heads[0])->next;
    for (i = 1; i < 10; i++)
    {   
        ListNode* n = find_end(p_main_head);
        n->next = (p_heads[i])->next;
    }
    ListNode* n = find_end(p_main_head);
    // Last node gets null
    n->next = NULL;
}

int main(int argc, char** argv)
{
    ListNode **head_pointers, **tail_pointers;
    ListNode* main_head;
    main_head = newList();

    int total_size = 0;
    if (argc != 5)
        return 1;

    // Init the list and the head pointers
    head_pointers = malloc(10 * sizeof(ListNode));
    tail_pointers = malloc(10 * sizeof(ListNode));
    int i;
    for (i = 0; i < 10; i++)
    {
        head_pointers[i] = newList();
        tail_pointers[i] = newList();
    }


    int seed = atoi(argv[1]);
    int N = atoi(argv[2]);
    int min = atoi(argv[3]);
    int max = atoi(argv[4]);

    if (max <= min)
    {
        printf("Max size was smaller than min size.\n");
        return 1;
    }

    // This will give the max size
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
        int* c_rep = getCharRep(num, total_size - 1);
        assert(main_head != NULL);
        assert(c_rep != NULL);
        insert(main_head, num, c_rep);        
    }
    assert(head_pointers != NULL);
    assert(tail_pointers != NULL);
    assert(main_head != NULL);
    assert(total_size != 0);

    // Sort the list by radix
    radix_sort(head_pointers, tail_pointers, &main_head, total_size);
    printf("The final sorted list is:\n");
    printList(main_head);

    // Clean up.
    delete_entire_list(main_head);
    
    int j;
    for (j = 0; j <10; j++)
    {
        delete_entire_list(head_pointers[j]);
        delete_entire_list(tail_pointers[j]);
    }

    // Free the arrays after the nodes are deleted.
    free(head_pointers);
    free(tail_pointers);
    return 0;
}
