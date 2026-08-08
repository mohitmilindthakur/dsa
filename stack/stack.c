#include <stdlib.h>
#include "stack.h"

static Node *create_node(void *data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Stack *create_stack(void)
{
    Stack *stack = malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack *stack, void *data)
{
    Node *node = create_node(data);
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

void *peek(Stack *stack)
{
    if (stack->size == 0)
    {
        return NULL;
    }
    return stack->head->data;
}

bool pop(Stack *stack, void **out)
{
    if (stack->size == 0)
    {
        return false;
    }
    Node *node = stack->head;
    if (out != NULL)
    {
        *out = node->data;
    }
    stack->head = node->next;
    stack->size--;
    free(node);
    return true;
}

void destroy_stack(Stack *stack)
{
    void *data;
    while (pop(stack, &data))
    {
        /* caller owns data; we only free nodes */
    }
    free(stack);
}
