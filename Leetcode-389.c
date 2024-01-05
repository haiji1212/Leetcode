#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//【389】找不同
// 给定两个字符串 s 和 t ，它们只包含小写字母。
// 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
// 请找出在 t 中被添加的字母。

char findTheDifference(char* s, char* t) {
    int num[26] = {0};  //小写字母表
    while(*s){
        num[*s - 'a'] ++;
        s ++;
    }
    while(*t){
        num[*t - 'a'] --;
        if(num[*t -'a'] < 0){
            return *t;
        }
        t ++;
    }
    return '\0';
}

int main()
{
    char str1[1000] = "abce";
    char str2[1001] = "abcde";
    char result = findTheDifference(str1, str2);
    printf("%c\n", result);
    return 0;
}