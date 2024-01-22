#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// 【67】二进制求和
// 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
#define max(a, b) (a > b ? a : b)

char* addBinary(char *a, char *b){
    int a_len = strlen(a);
    int b_len = strlen(b);
    // 需要一个额外的位置保存'\0'，需要一个额外的位置保存可能的最高位进位
    int ans_len = max(a_len, b_len) + 1 + 1;

    char *ans = malloc(sizeof(char) * ans_len);
    ans[0] = '0';   // 默认两数相加没有最高位进位
    ans[ans_len - 1] = '\0';

    int c = 0;      // 进位
    int i = a_len - 1, j = b_len - 1, k = ans_len - 2;      // 从末尾开始各个位相加
    while (i >= 0 || j >= 0) {
        int a_bit = i >= 0 ? a[i] - '0' : 0;
        int b_bit = j >= 0 ? b[j] - '0' : 0;
        int bit_sum = a_bit + b_bit + c;

        ans[k] = '0' + bit_sum % 2;

        c = bit_sum / 2;
        --i;--j;--k;
    }

    if (c != 0)
        ans[k] = '1';

    return ans[0] == '0' ? ans + 1 : ans;
}
