#include "link.h"



int main()
{
    ListNode* head = newList();
    insert(head, 8);
    insert(head->next, 10);
    insert(head, 15);
    insert(head->next, 57);
    insert_tail(head, 67);
    insert_tail(head, 45); 
    printList(head);
    return 0;
}
