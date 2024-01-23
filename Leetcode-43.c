#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// 【43】字符串相乘
// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

char* multiply(char* num1, char* num2) {
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int totalLength = length1 + length2;
    int charIndex = 0, valueIndex = 0;
    int* value = (int*)malloc(sizeof(int) * totalLength);
    memset(value, 0, sizeof(int) * totalLength);
    char* result = (char*)malloc(sizeof(char) * (totalLength + 1));
    for(int i = length1 - 1 ; i >= 0; i --){
        for(int j = length2 - 1; j >= 0; j--){
            value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for(int i = totalLength - 1; i > 0; i --){
        value[i - 1] += value[i] / 10;
        value[i] %= 10;
    }
    while(value[valueIndex] == 0 && valueIndex < totalLength - 1){
        valueIndex ++;
    }
    while(valueIndex < totalLength){
        result[charIndex++] = value[valueIndex++] + '0';
    }
    result[charIndex] = '\0';
    return result;
}
