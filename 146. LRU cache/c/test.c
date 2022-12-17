#include <stdio.h>
#include <assert.h>
#include "lru_cache.h"

int main() {
    printf("\n== Test start ==\n");

    struct LRUCache* obj = lRUCacheCreate(2);
    int val;

    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 2);

    val = lRUCacheGet(obj, 1);
    assert(val == 1);

    lRUCachePut(obj, 3, 3);

    val = lRUCacheGet(obj, 2);
    assert(val == -1);

    lRUCachePut(obj, 4, 4);

    val = lRUCacheGet(obj, 1);
    assert(val == -1);

    val = lRUCacheGet(obj, 3);
    assert(val == 3);

    val = lRUCacheGet(obj, 4);
    assert(val == 4);

    lRUCacheFree(obj);
    printf("== Test finish ==\n");
}

/*
    Input
    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
    [null, null, null, 1, null, -1, null, -1, 3, 4]

    Explanation
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
*/

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/
