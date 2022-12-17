#include <stdbool.h>

typedef struct LRUCache cache;

struct LRUCache* lRUCacheCreate(int capacity);

int lRUCacheGet(struct LRUCache* obj, int key);
void lRUCachePut(struct LRUCache* obj, int key, int value);
void lRUCacheFree(struct LRUCache* obj);
