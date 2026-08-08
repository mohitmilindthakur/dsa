#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LL
{
    Node *head;
    Node *tail;
    int size;
} LL;

typedef void (*foreach)(Node *node);

LL *create_linked_list()
{
    LL *ll = malloc(sizeof(LL));
    return ll;
}

Node *create_node(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    return node;
}

Node *append_node(LL *ll, int data)
{
    Node *node = create_node(data);
    if (ll->tail == NULL)
    {
        ll->head = node;
        ll->tail = node;
    }
    else
    {
        ll->tail->next = node;
        ll->tail = node;
    }
    ll->size = ll->size + 1;

    return node;
}

void list_foreach(LL *ll, foreach fn)
{
    Node *curr = ll->head;
    for (int i = 0; i < ll->size; i++)
    {
        fn(curr);
        curr = curr->next;
    }
}

void print_ll(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}
static void print_node(Node *node)
{
    printf("%d\n", node->data);
}

void print_all(LL *ll)
{
    // Node *curr = ll->head;
    // while (true)
    // {
    //     printf("%d\n", curr->data);
    //     if (curr->next == NULL)
    //     {
    //         break;
    //     }
    //     curr = curr->next;
    // }
    list_foreach(ll, print_node);
}

Node *get_kth_element(LL *ll, int index)
{
    if (index >= ll->size)
    {
        return NULL;
    }
    Node *curr = ll->head;
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    return curr;
}

bool is_present(LL *ll, int data)
{
    Node *curr = ll->head;
    for (int i = 0; i < ll->size; i++)
    {
        if (data == curr->data)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool is_valid_index(LL *ll, int index)
{
    return index < ll->size;
}

void insert_node(LL *ll, int data, int index)
{
    if (!is_valid_index(ll, index))
    {
        return;
    }

    Node *curr = ll->head;
    Node *new_node = create_node(data);

    if (index == 0)
    {
        ll->head = new_node;
        ll->head->next = curr;
        ll->size = ll->size + 1;
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        curr = curr->next;
    }

    // printf("Node %d", new_node->data);

    new_node->next = curr->next;
    curr->next = new_node;

    ll->size = ll->size + 1;
}

void delete_node(LL *ll, int data)
{
    Node *curr = ll->head;

    if (curr->data == data)
    {
        ll->head = curr->next;
        ll->size = ll->size - 1;
        free(curr);
        return;
    }

    while (curr->next != NULL)
    {
        if (curr->next->data == data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            ll->size = ll->size - 1;
            free(temp);
            return;
        }
        curr = curr->next;
    }
}

Node *reverse_node(Node *curr, LL *ll)
{
    // printf("%d\n", curr->data);
    if (curr->next == NULL)
    {
        ll->head = curr;
        return curr;
    }
    Node *temp = reverse_node(curr->next, ll);
    temp->next = curr;
    curr->next = NULL;
    // printf("%d\n", curr->data);
    return curr;
}

void reverse(LL *ll)
{
    Node *new_head = NULL;
    reverse_node(ll->head, ll);
}

void reverse_temp(LL *ll)
{
    Node *curr = ll->head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        if (curr == NULL)
        {
            ll->head = prev;
        }
    }
}

void delete_duplicate_sorted(LL *ll)
{
    Node *curr = ll->head;

    while (curr != NULL)
    {
        while (curr->next != NULL && curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
            ll->size = ll->size - 1;
        }
        curr = curr->next;
    }
}

Node *get_middle_node(Node *head)
{
    Node *fp = head;
    Node *sp = head;
    int spCount = 0;

    while (fp->next != NULL && fp->next->next != NULL)
    {
        sp = sp->next;
        fp = fp->next->next;
        spCount++;
    }
    return sp;
}

Node *merge_sorted(Node *h1, Node *h2)
{
    Node *head = NULL;
    Node *tail = NULL;

    if (h1->data > h2->data)
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
    printf("h1 -> %p", h1);
    printf("h2 -> %p", h2);

    while (h1 != NULL || h2 != NULL)
    {
        if (h1 == NULL && h2 != NULL)
        {
            tail->next = h2;
            printf("%d", 1);
            break;
        }
        if (h2 == NULL && h1 != NULL)
        {
            tail->next = h1;
            printf("%d", 2);
            break;
        }
        if (h2->data <= h1->data)
        {
            tail->next = h2;
            tail = h2;
            h2 = h2->next;
        }
        else
        {
            tail->next = h1;
            tail = h1;
            h1 = h1->next;
            printf("%d", 4);
        }
    }
    return head;
}

Node *merge_sort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *middle = get_middle_node(head);
    Node *head1 = middle->next;
    middle->next = NULL;

    head = merge_sort(head);
    head1 = merge_sort(head1);

    Node *sorted = merge_sorted(head, head1);
    return sorted;
}

bool detect_cycle_in_linked_list(Node *head)
{
    Node *fp = head;
    Node *sp = head;
    bool has_cycle = false;

    while (fp->next != NULL && fp->next->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;

        if (fp == sp)
        {
            has_cycle = true;
            break;
        }
    }

    if (!has_cycle)
    {
        return false;
    }

    Node *t = head;
    while (t != fp)
    {
        t = t->next;
        fp = fp->next;
    }

    Node *circular_point = t;

    while (sp->next != circular_point)
    {
        sp = sp->next;
    }

    sp->next = NULL;
    return true;
}

Node *reverse_ll(Node *A)
{
    Node *curr = A;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int is_palindrome(Node *A)
{
    Node *reversed = reverse_ll(A);
    Node *h1 = A;
    Node *h2 = reversed;

    print_ll(h1);

    while (h1 != NULL)
    {
        // printf("Comparing %d and the %d\n", h1->data, h2->data);
        if (h1->data != h2->data)
        {
            return 0;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return 1;
}

int main()
{
    LL *ll = create_linked_list();
    LL *ll2 = create_linked_list();
    append_node(ll, 1);
    append_node(ll, 1);
    append_node(ll, 6);
    append_node(ll, 4);
    append_node(ll, 1);
    // append_node(ll, 20);
    // // append_node(ll, 1);
    // append_node(ll, 1);
    // // append_node(ll, 2);
    // // append_node(ll, 2);
    // append_node(ll, 2);
    // append_node(ll, 5);
    // append_node(ll, 0);
    // append_node(ll, -20);
    // Node *node = append_node(ll, 50);
    // Node *last_node = append_node(ll, -25);
    // last_node->next = node;
    // printf("\n%p-------------\n", ll->tail->next);

    // append_node(ll2, 2);
    // append_node(ll2, 4);
    // append_node(ll2, 6);
    // append_node(ll2, 8);
    // append_node(ll2, 10);
    // append_node(ll2, 11);
    // append_node(ll2, 15);
    // Node *node = reverse_node(ll, ll->head);
    // print_all(ll);
    // printf("-------------------\n");
    // reverse(ll);
    // reverse_temp(ll);
    // printf("%d\n", node->data);
    // printf("%d\n", node->next->data);
    // printf("%d\n", node->next->next->data);

    // printf("%p\n", get_kth_element(ll, 5));
    // printf("%d\n", get_kth_element(ll, 5)->data);

    // delete_duplicate_sorted(ll);
    // print_all(ll);
    // printf("-------------------\n");
    // print_all(ll2);

    // Node *sorted = merge_sorted(ll, ll2);
    // print_ll(sorted);
    // printf("-------------------\n");
    // print_all(ll);
    // printf("%d\n", get_middle_node(ll));
    // printf("%b\n", is_present(ll, 69));
    // Node *sorted = merge_sort(ll->head);
    // print_ll(ll->head);

    // bool has_cycle = detect_cycle_in_linked_list(ll->head);
    // printf("%b\n", has_cycle);
    // print_ll(ll->head);

    printf("%d\n", is_palindrome(ll->head));
}
