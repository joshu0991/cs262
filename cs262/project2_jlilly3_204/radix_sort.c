#include "link.h"

void radix_sort(ListNode** p_head_pointers, ListNode** p_tail_pointers, ListNode* p_main_head, int p_size);
void stitch_together(ListNode** p_heads, ListNode** p_tails, ListNode** p_main_head);

void radix_sort(ListNode** p_head_pointers, ListNode** p_tail_pointers, ListNode* p_main_head, int p_size)
{
    int i;
    ListNode* curser;
    curser = p_main_head->next;
    // This is the main loop responsible for accessing the appropriate positions of the number ie ones tens etc.
    for (i = p_size - 1; i >= 0; i--)
    {
        // Sort every number in the list into the appropraite bucket.
            printList(p_main_head);
        while (curser != NULL)
        {
            int position_num = (curser->c_rep)[i];
            move(p_tail_pointers, p_head_pointers, &p_main_head, &curser, position_num);
            curser = p_main_head->next;
            printList(p_head_pointers[0]);
        }
        // Stitch together the buckets
        stitch_together(p_head_pointers, p_tail_pointers, &p_main_head);       
        printList(p_main_head);
    }
}

void stitch_together(ListNode** p_heads, ListNode** p_tails, ListNode** p_main_head)
{
    int i;
    (*p_main_head)->next = (p_heads[0])->next;
    //printList(p_main_head);
    for (i = 1; i < 10; i++)
    {   
    printf("heads at i\n");
    printList(p_heads[i]);    
        ListNode* n = find_end(p_main_head);
        n->next = (p_heads[i])->next;
    }
    ListNode* n = find_end(p_main_head);
    n->next = NULL;
    printList(*p_main_head);    
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
        insert(main_head, num, c_rep);        
    }
    printList(main_head);
    radix_sort(head_pointers, tail_pointers, main_head, total_size);
 //   printList(main_head);

    // Clean up all of the head nodes.
    int j;
    for (j = 0; j <10; j++)
    {
        delete_entire_list(head_pointers[j]);
    }

    free(head_pointers);
    free(tail_pointers);
    return 0;
}
