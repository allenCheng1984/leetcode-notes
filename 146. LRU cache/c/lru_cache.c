#include <stdbool.h>
#include <stdlib.h>
#include "../../libs/uthash.h"

/* use uthash */

struct Node {
    int key;
    int value;
    struct Node *next;
    struct Node *prev;
    UT_hash_handle hh;
};

typedef struct {
    int size;
    int capacity;
    struct Node *head;
    struct Node *tail;
    struct Node *hash;
} LRUCache;

// hash operations
// add, find, delete
struct Node *addHashNode(LRUCache *cache, int key, int value)
{
    struct Node *n;
    HASH_FIND_INT(cache->hash, &key, n);

    if (n==NULL) {
        n = (struct Node*) malloc(sizeof(struct Node));
        n->key = key;
        HASH_ADD_INT(cache->hash, key, n);
    }

    n->value = value;
    return n;
}

struct Node *findHashNode(LRUCache *cache, int key)
{
    struct Node *n;
    HASH_FIND_INT(cache->hash, &key, n);
    return n;
}

void deleteHashNode(LRUCache *cache, struct Node *n)
{
    HASH_DEL(cache->hash, n);
}

void deleteAllHashNodes(LRUCache *cache)
{
    struct Node *current, *temp;

    HASH_ITER(hh, cache->hash, current, temp) {
        HASH_DEL(cache->hash, current);
        free(current);
    }
}

// dll operations
// add, remove, moveToHead
void addNode(LRUCache *cache, struct Node *node)
{
    node->prev = cache->head;
    node->next = cache->head->next;

    cache->head->next->prev = node;
    cache->head->next = node;
}

void removeNode(LRUCache *cache, struct Node *node)
{
    struct Node *prev = node->prev;
    struct Node *next = node->next;

    prev->next = next;
    next->prev = prev;
}

void moveNodeToHead(LRUCache *cache, struct Node *node)
{
    removeNode(cache, node);
    addNode(cache, node);
}

struct Node *popTail(LRUCache *cache)
{
    struct Node *res = cache->tail->prev;
    removeNode(cache, res);
    return res;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache *) malloc(sizeof(LRUCache));
    cache->size = 0;
    cache->capacity = capacity;
    cache->hash = NULL;
    cache->head = (struct Node *)malloc(sizeof(struct Node));
    cache->tail = (struct Node *)malloc(sizeof(struct Node));

    // init the sentinel nodes
    cache->head->prev = NULL;
    cache->head->next = cache->tail;
    cache->tail->next = NULL;
    cache->tail->prev = cache->head;

    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    struct Node *n = findHashNode(obj, key);

    if (n == NULL)
        return -1;

    moveNodeToHead(obj, n);
    return n->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    struct Node *n = findHashNode(obj, key);

    if (n == NULL) {
        n = addHashNode(obj, key, value);
        addNode(obj, n);
        obj->size++;

        if (obj->size > obj->capacity) {
            n = popTail(obj);
            deleteHashNode(obj, n);
            obj->size--;
        }
    }
    else {
        n->value = value;
        moveNodeToHead(obj, n);
    }
}

void lRUCacheFree(LRUCache* obj) {
    deleteAllHashNodes(obj);
    free(obj->head);
    free(obj->tail);
    free(obj);
}
