//! Joshua Lilly G00561467
//! Project II Radix Sort Linked Lists.
//! October 31, 2015

#include "link.h"

//! make a new list with a dummy head
ListNode* newList(void)
{
    ListNode* dummy;
    dummy = (ListNode *)malloc(sizeof(ListNode));
    dummy->next = NULL;
    return dummy;
}

//! Print the list
void printList(ListNode* head)
{
    ListNode* curr;
    curr = head->next;
    int len = 0;
    while (curr != NULL)
    {
        if (len == 8)
        {
            printf("\n");
            len = 0;
        }
        printf("%10d ",curr->num);
        len++;
        curr = curr->next;
    }
    printf("\n");
}

//! insert a node at the front.
void insert(ListNode* p_prev, int p_number, int* p_c_rep)
{
    ListNode *next, *new_node;
    new_node = (ListNode*)malloc(sizeof(ListNode));
    if (!new_node)
        return;
    // Insert at the front
    new_node->num = p_number;
    new_node->c_rep = p_c_rep;

    next = p_prev->next;
    p_prev->next = new_node;
    new_node->next = next;
}

//! Insert a node at the end of the list
void insert_tail(ListNode* p_tail, ListNode** p_to_insert)
{
    ListNode* curr;    
    curr = p_tail->next;
    if (curr)
        curr->next = *p_to_insert;
    
    // This node will be the new end it needs to point to null 
   (*p_to_insert)->next = NULL;
    p_tail->next = *p_to_insert;
}

//! Find the node prior to the given.
ListNode* find_previous(ListNode** p_head, ListNode** p_target)
{
    ListNode* curr;
    curr = *p_head;

    // While the next isn't null
    while (curr->next != NULL)
    {
        if ((curr->next) == *p_target)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

//! Delete the node from the given list
void delete_node(ListNode** p_head, ListNode**  p_target)
{
    // runtime check
    if (!p_head)
        return;

    // Get the previous node
    ListNode* previous = find_previous(p_head, p_target);

    if (!previous)
        return;
 
    // get the node after the target
    ListNode* after_target = (*p_target)->next;

    // Relink
    previous->next = after_target;
}

//! Frees all memory
void delete_entire_list(ListNode* p_head)
{
    ListNode* curr, *temp;
    curr = p_head;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        if (temp != p_head)
            free(temp->c_rep);
        free(temp);
    }
}

//! Convert an int to an array
int* getCharRep(int p_num, int p_size)
{
    int* value = malloc(((p_size + 1) * sizeof(int)));
    int i;
    for (i = 0; i < p_size; i++)
    {
       // Init the array with zeros 
       value[i] = 0;
    }

    // While the remaining num isn't zero
    while (p_num)
    {
        // Digit starts at right
        int digit = p_num % 10;

        // Divid by ten puts number in last position
        p_num /= 10;

        // Start at the end.
        value[p_size--] = digit;
    }

    // Return the integer array
    return value;
}

//! Find the end of the list and return it
ListNode* find_end(ListNode** p_head)
{
    ListNode *curr, *prev;
    curr = *p_head;
    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    return prev;
}

// remove a node from the src head and put it on the dest tail
void move(ListNode** p_dest_tail, ListNode** p_dest_head, ListNode** p_src_head, ListNode** p_move, int p_pos)
{
    // Delete the node from the old list.
    delete_node(p_src_head, p_move);
 
    // Move to the head and link up if the head is null
    if ((p_dest_head[p_pos])->next == NULL)
    {
        p_dest_head[p_pos]->next = *p_move;
        p_dest_tail[p_pos]->next = *p_move;
        (*p_move)->next = NULL;
    }
    // Otherwise put at the tail
    else
    {          
        insert_tail(p_dest_tail[p_pos], p_move); 
    }
}
