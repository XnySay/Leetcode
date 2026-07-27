#include <stdio.h>

int climbStairs(int n) {
    int sum;
    if(n>3)
        sum = climbStairs(n-1) + climbStairs(n-2);
    else
        return n;
    return sum;
}

int main(void) {
    int n;
    scanf("%d",&n);
    int a = climbStairs(n);
    printf("%d",a);
    return 0;
}
