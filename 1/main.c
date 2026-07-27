#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int index;
} HashTableItem;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTableItem* hashTable = (HashTableItem*)malloc(numsSize * sizeof(HashTableItem));
    if (!hashTable) return NULL;

    for (int i = 0; i < numsSize; i++) {
        hashTable[i].key = nums[i];
        hashTable[i].index = i;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        for (int j = 0; j < numsSize; j++) {
            if (hashTable[j].key == complement && hashTable[j].index != i) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = hashTable[j].index;
                result[1] = i;
                *returnSize = 2;
                free(hashTable);
                return result;
            }
        }
    }

    free(hashTable);
    *returnSize = 0;
    return NULL;
}
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result); // 释放动态分配的内存
    } else {
        printf("No solution found.\n");
    }

    return 0;
}