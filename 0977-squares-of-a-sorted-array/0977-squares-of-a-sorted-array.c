#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {

    int *result = (int*)malloc(sizeof(int) * numsSize);

    int left = 0;
    int right = numsSize - 1;
    int pos = numsSize - 1;

    while(left <= right)
    {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];

        if(leftSq > rightSq)
        {
            result[pos] = leftSq;
            left++;
        }
        else
        {
            result[pos] = rightSq;
            right--;
        }

        pos--;
    }

    *returnSize = numsSize;
    return result;
}