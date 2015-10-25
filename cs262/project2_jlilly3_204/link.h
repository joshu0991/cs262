#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node 
{
    int num; 
    struct Node* next;
}ListNode;

int insert(struct Node* prev, int num);                        // inserts a new node \return 0 on success 1 on failure
int insert_tail(struct Node* head, int num);                   // insert a new node at the tail
struct Node* delete_node(struct Node* prev);                   // deletes the node after previous
struct Node* newList(void);                                    // make a new list with a dummy head
void printList(struct Node* head);                             // print the list
struct Node* find_previous(struct Node* head, int number);     // find the position of the prev node for number
