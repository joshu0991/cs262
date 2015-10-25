#include "link.h"

//! make a new list with a dummy head
ListNode* newList(void)
{
    ListNode *dummy;
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
    while (curr !=NULL)
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

int insert(ListNode* p_prev, int p_number)
{
    ListNode *next, *new_node;
    new_node = (ListNode*)malloc(sizeof(ListNode));
    if (!new_node)
        return 1;
    new_node->num = p_number;
    next = p_prev->next;
    p_prev->next = new_node;
    new_node->next = next;
    return 0;
}

int insert_tail(ListNode* p_head, int p_number)
{
    ListNode *curr, *new_node;
    
    // Set up new node
    new_node = (ListNode*)malloc(sizeof(ListNode));
    if (!new_node)
        return 1;
    new_node->num = p_number;
    // This node will be the new end
    new_node->next = NULL;

    // Find the end
    curr = p_head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
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

void delete_node(ListNode* p_head, int p_target)
{
    ListNode* previous = find_previous(p_head, p_target);

    // The standard unix approach is to ignore user stupidity.
    if (previous == NULL)
    {
        return;
    }
    
    ListNode* target = previous->next;
    ListNode* after_target = target->next;

    previous->next = after_target;

    free(target);
}

void delete_entire_list(ListNode* p_head)
{

    ListNode* curr;
    curr = p_head;
    while (curr != NULL)
    {
        ListNode* temp;
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}
