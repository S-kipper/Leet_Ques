/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. */



#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* rarr = malloc(2 * sizeof(int)); // Creating a new array to return the
                                         // elements that add up to the target
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                rarr[0] = i;
                rarr[1] = j;
                *returnSize = 2; // Used to say how big the return size is
                return rarr;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* indices = twoSum(nums, 4, target, &returnSize);

    if (indices != NULL) {
        printf("Indices: %d, %d\n", indices[0], indices[1]);
        free(indices); // Free the memory allocated for the indices array
    } else {
        printf("No two elements add up to the target.\n");
    }

    return 0;
}

