#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Stack
{
    struct Node *head;
    int size;
} Stack;

Stack *create_stack(void);
void push(Stack *stack, void *data);
void *peek(Stack *stack);
bool pop(Stack *stack, void **out);
void destroy_stack(Stack *stack);

#endif
