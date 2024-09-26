#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0; // 定义搜索范围的左边界
    int right = numsSize - 1; // 定义搜索范围的右边界

    while (left <= right) {
        int mid = left + (right - left) / 2; // 计算中间位置的索引
        if (nums[mid] == target) {
            return mid; // 如果中间元素正好是目标值，直接返回索引
        } else if (nums[mid] < target) {
            left = mid + 1; // 如果中间元素小于目标值，调整左边界
        } else {
            right = mid - 1; // 如果中间元素大于目标值，调整右边界
        }
    }

    // 循环结束，说明目标值不在数组中，返回 left 即为插入位置
    return left;
}

int main(void) {



    return 0;
}
