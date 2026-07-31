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

void append_node(LL *ll, int data)
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

int main()
{
    LL *ll = create_linked_list();
    append_node(ll, 1);
    append_node(ll, 1);
    append_node(ll, 2);
    append_node(ll, 2);
    append_node(ll, 2);
    append_node(ll, 3);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    append_node(ll, 4);
    // delete_node(ll, 42);
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

    delete_duplicate_sorted(ll);
    print_all(ll);
    // printf("%b\n", is_present(ll, 69));
}
