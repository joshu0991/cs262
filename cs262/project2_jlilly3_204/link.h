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
int insert_tail(struct Node* tail, struct Node** p_to_insert);  // insert a new node at the tail
void delete_node(struct Node** p_head, struct Node** p_target);   // deletes the node after previous
struct Node* newList(void);                                    // make a new list with a dummy head
void printList(struct Node* head);                             // print the list
ListNode* find_previous(ListNode** p_head, ListNode** p_target);
void delete_entire_list(struct Node* p_head);
int* getCharRep(int p_num, int p_size); 
int size(struct Node* p_head);
void move(ListNode** p_dest_tail, ListNode** p_dest_head, ListNode** p_src_head, ListNode** p_move, int p_pos);
ListNode* find_end(ListNode** p_head);
