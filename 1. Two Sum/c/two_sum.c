#include "../../libs/uthash.h"

typedef struct {
  int key;   // for hash table's key
  int index; // for index of nums
  UT_hash_handle hh;
} hash_t;

void hash_free(hash_t **head) {
  hash_t *current, *temp;

  HASH_ITER(hh, *head, current, temp) {
    HASH_DEL(*head, current);
    free(current);
  }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  hash_t *head = NULL;
  hash_t *element;
  int *result = (int*) malloc(2 * sizeof(int));
  int remaining;
  for (int i = 0; i < numsSize; ++i) {
    remaining = target - nums[i];

    // Find if there has already been an element such that the sum is target
    HASH_FIND_INT(head, &remaining, element);
    if (element) {
      result[0] = element->index;
      result[1] = i;
      break;
    }

    // Add the new number to the hash head if it doesn't exist already
    HASH_FIND_INT(head, &nums[i], element);
    if (!element) {
      element = (struct hash_t *) malloc(sizeof(*element));
      element->key = nums[i];
      element->index = i;

      HASH_ADD_INT(head, key, element);
    }
  }

  hash_free(&head);

  *returnSize = 2;
  return result;
}
