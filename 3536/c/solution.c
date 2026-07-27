#include <stdio.h>
#include <stdlib.h>

int maxProduct(int n) {
    int max2[2] = {0,0};
    while (n > 0)
    {
        int d = n % 10;
        if (d > max2[0]) {
            max2[1] = max2[0];
            max2[0] = d;
        } else if (d > max2[1]) {
            max2[1] = d;
        }
        n /= 10;
    }
    return max2[0] * max2[1];
}


//节省内存
int maxProduct1(int n) {
    int first = 0, second = 0;
    while (n > 0) {
        int x = n % 10;
        if (x > first) {
            second = first;
            first = x;
        } else if (x > second) {
            second = x;
        }
        n /= 10;
    }
    return first * second;
}


int main(void) {

    int n;
    printf("请输入正整数");
    scanf("%d", &n);

    printf("任意两位数字相乘的结果为：%d\n", maxProduct(n));

    return 0;
}