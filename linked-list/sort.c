#include <stdio.h>
#include <stdlib.h>
typedef struct listnode
{
    int val;
    struct listnode *next;
} listnode;

listnode *listnode_new(int val)
{
    listnode *node = malloc(sizeof(listnode));
    node->val = val;
    node->next = NULL;
    return node;
}

listnode *mergeTwoLists(listnode *A, listnode *B)
{
    if (A == NULL)
    {
        return B;
    }
    if (B == NULL)
    {
        return A;
    }
    listnode *h1 = A;
    listnode *h2 = B;
    listnode *tail = NULL;
    listnode *head = NULL;

    if (h1->val > h2->val)
    {
        head = h2;
        tail = h2;
        h2 = h2->next;
    }
    else
    {
        head = h1;
        tail = h1;
        h1 = h1->next;
    }

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->val < h2->val)
        {
            tail->next = h1;
            tail = h1;
            h1 = h1->next;
        }
        else
        {
            tail->next = h2;
            tail = h2;
            h2 = h2->next;
        }
    }
    if (h1 == NULL)
    {
        tail->next = h2;
    }
    else if (h2 == NULL)
    {
        tail->next = h1;
    }
    return head;
}

listnode *get_middle_node(listnode *A)
{
    listnode *sp = A;
    listnode *fp = A;

    while (fp != NULL && fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
    }

    return sp;
}

listnode *sortList(listnode *A)
{
    if (A == NULL || A->next == NULL)
    {
        return A;
    }
    listnode *mid = get_middle_node(A);
    listnode *h1 = mid->next;
    mid->next = NULL;

    A = sortList(A);
    h1 = sortList(h1);
    listnode *sorted = mergeTwoLists(A, h1);
    return sorted;
}

void main()
{
}