#include <stdio.h>
#include <stdlib.h>
typedef struct dll
{
    int data;
    struct dll *next;
    struct dll *prev;
} dll;

dll *create_dll_node(int data)
{
    dll *node = malloc(sizeof(dll));
    node->data = data;
    return node;
}

dll *insert_at(dll *head, int index, int data)
{
    dll *curr = head;
    dll *new_node = create_dll_node(data);
    if (index == 0)
    {
        new_node->next = head;
        head->prev = new_node;
        return new_node;
    }
    int curr_index = 0;
    while (curr_index < index - 1)
    {
        curr = curr->next;
        curr_index++;
    }
    new_node->next = curr->next;
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
    new_node->prev = curr;
    curr->next = new_node;
    return head;
}

dll *append(dll *head, int data)
{
    dll *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    dll *new_node = create_dll_node(data);
    curr->next = new_node;
    new_node->prev = curr;
    return head;
}

void print_dll(dll *head)
{
    dll *curr = head;
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

dll *delete_by_key(dll *head, int key)
{
    dll *curr = head;
    while (curr != NULL && curr->data != key)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    if (curr->prev == NULL)
    {
        if (curr->next == NULL)
        {
            return NULL;
        }
        curr->next->prev = NULL;
        return curr->next;
    }
    curr->prev->next = curr->next;
    if (curr->next != NULL)
    {
        curr->next->prev = curr->prev;
    }
    return head;
}

void main()
{
    dll *head = create_dll_node(1);
    head = append(head, 2);
    head = insert_at(head, 2, 3);
    head = append(head, 4);
    head = append(head, 5);
    head = delete_by_key(head, 2);
    print_dll(head);
}