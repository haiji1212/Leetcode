#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//【28】找出字符串中第一个匹配项的下标
// 给你两个字符串 haystack 和 needle ，
// 请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
// 如果 needle 不是 haystack 的一部分，则返回  -1 。

int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);
    if(hLen < nLen) return -1;
    int i = 0, j = 0;
    while(i <= (hLen - nLen) && j < nLen){
        if(haystack[i+j] == needle[j]){
            j ++;
        }else{
            i ++;
            j = 0;
        }
    }
    return (j == nLen) ? i : -1;
}

int main()
{
    char str1[1000] = "asadbutsad";
    char str2[1000] = "sad";
    printf("%d\n", strStr(str1, str2));
    return 0;
}

