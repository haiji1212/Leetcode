#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//【1768】交替合并字符串
// 给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。
// 如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。
// 返回 合并后的字符串 。

char * mergeAlternately(char * word1, char * word2){
    char* res = (char*)malloc(sizeof(char) * (strlen(word1) + strlen(word2)) + 1);
    char* p = res;
    while(*word1 && *word2){
        *p ++ = *word1 ++;
        *p ++ = *word2 ++;
    }
    while(*word1){
        *p ++ = *word1 ++;
    }
    while(*word2){
        *p ++ = *word2 ++;
    }
    *p = '\0';
    return res;
}

int main()
{
    char str1[100] = "abcde";
    char str2[100] = "pqr";
    char *result = (char*)malloc(sizeof(char) * 200);
    result = mergeAlternately(str1, str2);
    printf("%s\n", result);
    return 0;
}