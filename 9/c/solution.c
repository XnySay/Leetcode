#include <stdio.h>
#include <stdbool.h>

// 判断是否为回文数
bool isPalindrome(int x) {
    // 负数一定不是回文；末尾为0且数字不是0，也不是回文
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reverseHalf = 0;
    // 翻转后半部分数字，直到前半段 <= 翻转后的后半段
    while (x > reverseHalf) {
        reverseHalf = reverseHalf * 10 + x % 10;
        x = x / 10;
    }

    // 偶数位：x == reverseHalf
    // 奇数位：去掉中间数字 x == reverseHalf / 10
    return (x == reverseHalf) || (x == reverseHalf / 10);
}

int main() {
    int num;
    printf("请输入一个整数：");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d 是回文数\n", num);
    } else {
        printf("%d 不是回文数\n", num);
    }

    return 0;
}