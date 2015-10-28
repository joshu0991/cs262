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

int insert(ListNode* p_prev, int p_number, int* p_c_rep)
{
    ListNode *next, *new_node;
    new_node = (ListNode*)malloc(sizeof(ListNode));
    if (!new_node)
        return 1;
    new_node->num = p_number;
    new_node->c_rep = p_c_rep;

    next = p_prev->next;
    p_prev->next = new_node;
    new_node->next = next;
    return 0;
}

int insert_tail(ListNode* p_tail, ListNode* p_to_insert)
{
    ListNode* curr;    
    curr = p_tail->next;
    curr->next = p_to_insert;
    p_to_insert->next = NULL;
    p_tail->next = p_to_insert;
    return 0; 
}

ListNode* find_previous(ListNode* p_head, int number)
{
    ListNode* curr;
    curr = p_head;
    while (curr->next != NULL)
    {
        if ((curr->next)->num == number)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

ListNode* delete_node(ListNode* p_head, int p_target)
{
    ListNode* previous = find_previous(p_head, p_target);

    // The standard unix approach is to ignore user stupidity.
    if (previous == NULL)
    {
        return NULL;
    }
    
    ListNode* target = previous->next;
    ListNode* after_target = target->next;

    previous->next = after_target;
    return target;
}

void delete_entire_list(ListNode* p_head)
{

    ListNode* curr;
    curr = p_head;
    while (curr != NULL)
    {
        ListNode* temp;
        temp = curr;
        if (curr != p_head)
            free(temp->c_rep);
        free(temp);
        curr = curr->next;
    }
}

int size(ListNode* p_head)
{
    ListNode* curr;
    curr = p_head;
    int counter = 0; 
    while (curr != NULL)
    {
        curr = curr->next;
        ++counter;
    }
    return counter;
}

int* getCharRep(int p_num, int p_size)
{
    int* value = malloc((p_size * sizeof(int)));
    int i;
    for (i = 0; i < p_size; i++)
    {
        value[i] = 0;
    }

    while (p_num)
    {
        int digit = p_num % 10;
        p_num /= 10;
        value[p_size--] = digit;
    }

    return value;
}

// remove a node from the src head and put it on the dest tail
void move(ListNode* p_dest_tail, ListNode* p_src_head, int value)
{
    ListNode* n;
    n = delete_node(p_src_head, value);
    if (n)
        insert_tail(p_dest_tail, n); 
}
