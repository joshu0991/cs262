//! Joshua Lilly G00561467
//! Project II Radix Sort Linked Lists.
//! October 31, 2015

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//! The linked list node.
typedef struct Node 
{
    int* c_rep;
    int num; 
    struct Node* next;
}ListNode;

/*!
 * Insert a new Node at the front of the list. Used for building the orig. list.
 * Node is created with malloc
 * param[in] p_prev previous node before the inserted
 * param[in] p_num the number to insert
 * param[in] p_c_rep the integer array rep of the integer.
 */
void insert(struct Node* p_prev, int p_num, int* p_c_rep);

/*!
 * Insert a given node at the tail of the given list
 * The node is not destroyed and recreated just moved.
 * param[in] p_tail the end of the list
 * param[in] p_to_insert the node to insert
 */
void insert_tail(struct Node* p_tail, struct Node** p_to_insert);

/*!
 * Delete the node from the given list the node is not freed just removed.
 * param[in] p_head the head of the list to delete from
 * param[in] p_target the target to delete
 */
void delete_node(struct Node** p_head, struct Node** p_target);

/*!
 * Create a new list head. The head is created with malloc
 * \return the new head
 */
struct Node* newList(void);

/*!
 * Print the list given the head
 * param[in] p_head the head of the list to print
 */
void printList(struct Node* p_head);

/*!
 * Find the node prior to the given node.
 * param[in] p_head the head of the list to find in
 * param[in] p_target the target to find the previous of.
 */
ListNode* find_previous(ListNode** p_head, ListNode** p_target);

/*!
 * Delete the entire list for good and return the memory to the heap.
 * param[in] p_head the head of the list to delete.
 */
void delete_entire_list(struct Node* p_head);

/*!
 * Get an array representation of the integer.
 * param[in] the p_num to get the char array of
 * param[in] the p_size of the largest number
 */
int* getCharRep(int p_num, int p_size); 

/*!
 * Move the given node to the given position of the node array and link up the tails.
 * param[in] p_dest_tail the array of node pointers to the tail
 * param[in] p_dest_head the array of node pointers to the heads
 * param[in] p_src_head a reference to the node to move.
 * param[in] p_pos the position(bucket) to insert the node in 
 */
void move(ListNode** p_dest_tail, ListNode** p_dest_head, ListNode** p_src_head, ListNode** p_move, int p_pos);

/*!
 * Find the end of the given list.
 * param[in] p_head a reference to the head of the array to find the end of.
 */
ListNode* find_end(ListNode** p_head);
