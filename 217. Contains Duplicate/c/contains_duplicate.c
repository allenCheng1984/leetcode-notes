#include <stdbool.h>
#include "../../libs/uthash.h"

// Approache:
// 1) build a hashtable
// 2) for num in nums:
//        if num not in hashtable:
//            add num into hashtable
//        else
//            return true
//    endloop
// 3) return false // every element is distinct

typedef struct {
    int key;           // id
    UT_hash_handle hh; // next prev hh_next hh_prev;
} element_t;

element_t *head = NULL;

void add(int key)
{
	element_t *n = malloc(sizeof(element_t));
	n->key = key;
    HASH_ADD_INT(head, key, n);
}

void hash_free()
{
    element_t *current, *temp;
    HASH_ITER(hh, head, current, temp){
        HASH_DEL(head, current);
        free(current);
    }
}

bool containsDuplicate(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++){
        element_t *n;
	    // check num in hashtable
        HASH_FIND_INT(head, &nums[i], n);
        if (n) {
            // if found, free memory and return true
            hash_free();
            return true;
        }
        else {
            // if not found, add num to hashtable
            add(nums[i]);
        }
    }

    // when this case, every num in nums is distinct.
	hash_free();
    return false;
}
