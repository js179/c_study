#include <stdio.h>

// 十进制转base进制
int hexConversion(int num, int base)
{
    if (num == 0)
        return num;
    return num % base + 10 * hexConversion(num / base, base);
}

// base进制转十进制
int decConversion(int num, int base)
{
    if (num == 0)
        return num;
    return num % 10 + base * decConversion(num / 10, base);
}

int main()
{
    int num;
    while (1)
    {
        printf("请输入：");
        scanf("%d", &num);

        int res7 = hexConversion(num, 7);
        int res2 = hexConversion(num, 2);

        printf("2进制: %d\n", res2);
        printf("7进制: %d\n", res7);

        int res21 = decConversion(res2, 2);
        int res71 = decConversion(res7, 7);
        printf("10进制: %d %d\n", res21, res71);
    }

    return 0;
}
