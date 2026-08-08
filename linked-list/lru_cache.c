typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct LRUCache
{
    int capacity;
    Node *head;
    Node *tail;
} LRUCache;

Node *create_node(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    return node;
}

Node *lru_cache()
{
}