#include <stdio.h>

#define MAX_BUFFER 100


int findGCD(int* nums, int numsSize) {
    int first = nums[0], second = nums[0];  // second 最小值
    for(int i = 1; i < numsSize; i++) 
    {
        if(nums[i] > first)
        {
            first = nums[i];
        }
        else if(nums[i] < second)
        {
            second = nums[i];
        }
    }
    while(second != 0)
    {
        int r = first % second;
        first = second;
        second = r;
    }
    return first;
}



int main(void)
{
    int size;
    printf("请输入数组长度：");
    scanf("%d", &size);

    // 根据输入的size定义数组
    int nums[size];
    int *p = nums;

    printf("请输入 %d 个整数(空格分隔)：\n", size);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &p[i]);
    }

    int ans = findGCD(p, size);
    printf("数组最大数与次大数的最大公约数：%d\n", ans);
    return 0;
}