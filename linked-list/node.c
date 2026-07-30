#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;
} Node;

Node *create_node(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    return node;
}

Node *append_node(Node *head, int data)
{
    Node *node = create_node(data);
    head->next = node;
    return node;
}

int main()
{
    printf("testing");
    Node *head = create_node(42);
    head = append_node(head, 69);

    printf("\n%p", head);
    printf("\n%d\n", head->data);
}
