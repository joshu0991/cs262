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
    ListNode* a = find_previous(head, 8);
    ListNode* b = find_previous(head, 57);
    ListNode* c = find_previous(head, 45);
    ListNode* d = find_previous(head, 15);
    printf("%d\n", a->num);
    printf("%d\n", b->num);
    printf("%d\n", c->num);
    printf("%d\n", d->num);
    delete_node(head, 8);
    printList(head);
    delete_node(head, 15);
    printList(head);
    delete_node(head, 45);
    printList(head);
   delete_entire_list(head); 
    return 0;
}
