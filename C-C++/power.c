#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*  Security power algorithm
*/
size_t secPower(int n, char res[], size_t len) 
{
    memset(res, 0, len);
    res[0] = 1 + '0';
    // for (int i = 0; i < len; i++)
    // {
    //     if (res[i] > 0)
    //     {
    //         printf("index: %d, value: %d\n", i, res[i]);
    //     }
    // }

    // printf("len: %lu\n", strlen(res));
    int carry = 0;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("Loop i: %d\n", i);
        carry = 0;
        size_t j = 0;
        for (j = 0; j < strlen(res) && j < len; j++)
        {
            // printf("Loop j: %lu\n", j);

            res[j] = res[j] - '0';
            // 先移位（乘与2）再加上低一位的进位数
            res[j] = (res[j] << 1) + carry;

            // 计算当前位的进位数
            carry = res[j] / 10;
            // 计算当前位的值
            res[j] = res[j] % 10 + '0';

            // printf("carry: %d, res: %d\n", carry, res[j]);
            
        }
        if(j >= len)
        {
            printf("res arry is to short...\n");
        }

        // 判断是否需要进位
        if (carry > 0)
        {
            res[j] += carry + '0';
        }
    }

    // reverse(res);
    return strlen(res);
}

int main(int argc, char *argv[])
{
    int n = 32;
    if (argc == 2)
    {
        n = atoi(argv[1]);
    }
    printf("n: %d\n", n);
    char narry[n/2];
    size_t len = secPower(n, narry, sizeof(narry));
    for (size_t i = strlen(narry); i > 0;  i--)
    {
        printf("%d",narry[i-1] - '0');
        // printf("index: %lu, value: %d\n", i, narry[i] - '0');
    }
    printf("\nlen: %lu\n", strlen(narry));
    return 0;
}
