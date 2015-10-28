#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node 
{
    int* c_rep;
    int num; 
    struct Node* next;
}ListNode;

int insert(struct Node* prev, int num, int* p_c_rep);          // inserts a new node \return 0 on success 1 on failure
int insert_tail(struct Node* head, struct Node* p_to_insert);  // insert a new node at the tail
struct Node* delete_node(struct Node* p_head, int p_target);   // deletes the node after previous
struct Node* newList(void);                                    // make a new list with a dummy head
void printList(struct Node* head);                             // print the list
struct Node* find_previous(struct Node* head, int number);     // find the position of the prev node for number
void delete_entire_list(struct Node* p_head);
int* getCharRep(int p_num, int p_size); 
int size(struct Node* p_head);
void move(struct Node* dest, struct Node* src, int value);
