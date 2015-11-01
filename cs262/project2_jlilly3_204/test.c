#include "link.h"

int main()
{
    ListNode* head = malloc(sizeof(ListNode));;
    ListNode* tail = malloc(sizeof(ListNode));;
    int* a = getCharRep(2, 1);
    insert(head, 2, a);
    tail->next = head->next;
    ListNode* n = malloc(sizeof(ListNode));
    n->num = 3;
    insert_tail(tail, n);
    printList(head);
}
