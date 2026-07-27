#include <stdio.h>
#include <string.h>

// 罗马数字转整数函数
int romanToInt(char *s) {
    int map[128] = {0};
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int sum = 0;
    int prev = 0;
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        int cur = map[s[i]];
        if (cur >= prev)
            sum += cur;
        else
            sum -= cur;
        prev = cur;
    }
    return sum;
}

int main() {
    // 定义字符数组存输入，长度足够容纳罗马数字
    char str[100];
    printf("请输入罗马数字：");
    // 读取一行输入（不含空格）
    scanf("%s", str);

    // 转换并输出结果
    int num = romanToInt(str);
    printf("对应整数：%d\n", num);

    return 0;
}