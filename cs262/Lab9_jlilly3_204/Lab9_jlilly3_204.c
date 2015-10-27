#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int m_data;
    struct Node* next;
}Node;

Node* find_previous(Node* p_head, int value);
void insertNodeSorted(Node* p_head, int i);
void printList(Node* p_head);
void delete_list(Node* p_head);

// ! \return node if it is in the list otherwise return head
Node* find_previous(Node* p_head, int value)
{
    Node* previous;
    previous = p_head;
    p_head = p_head->next;
    while (p_head != NULL && p_head->m_data <= value)
    {
        previous = p_head;
        p_head = p_head->next; 
    }
    // We got to the end of the list so the previous is the last element.
    return previous;
}

//! Insert and keep the list in order
void insertNodeSorted(Node* p_head, int i)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->m_data = i;
    new_node->next = NULL;

    // This is the first element in the list and a special case.
    if (p_head->next == NULL)
    {
        p_head->next = new_node;
        return;
    }

    Node *previous;
    if ((previous = find_previous(p_head, i)) != NULL)
    {
        new_node->next = previous->next;
        previous->next = new_node;
    }
}

//! Print each list in ascending order

void printList(Node* head)
{
    Node* curr;
    curr = head->next;
    int len = 0;
    printf ("The list printed out in order (top left smallest bottom right biggest)is: \n");
    while (curr != NULL)
    {
        if (len == 8)
        {
            printf("\n");
            len = 0;
        }
        printf("%10d ",curr->m_data);
        len++;
        curr = curr->next;
    }
    printf("\n");
}

//! Delete an entire list.
void delete_list(Node* p_head)
{
    Node* tmp;
    while(p_head != NULL)
    {
        tmp = p_head;
        p_head = p_head->next;
        free(tmp);
    }
}

int main(int argc, char** argv)
{
    // head os a dummy it contaoms no data
    Node* m_head = malloc(sizeof(Node));
    m_head->next = NULL;

    if (argc != 4)
        return 1;

    int seed = atoi(argv[1]);
    int n = atoi(argv[2]);
    int high = atoi(argv[3]);

    srand(seed);
    int i;
    for (i = 0; i < n; ++i)
    {
        // generate number
        int num = rand() % high + 1;
        printf("The new random number is: %d\n", num);

        // insert into list
        insertNodeSorted(m_head, num);
    }
    printList(m_head);
    delete_list(m_head);
    return 0;
}
