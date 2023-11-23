#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//【242】有效的字母异位词
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

bool isAnagram(char* s, char* t) {
    int Table[26] = {0};
    char* p = s;
    while(*p != '\0'){
        Table[*p - 'a'] ++;
        p++;
    }
    p = t;
    while(*p != '\0'){
        Table[*p - 'a'] --;
        p++;
    }    
    for(int i = 0; i < 26; i++){
        if(Table[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char string1[10] = "tcxhhi";
    char string2[10] = "hi";
    if(isAnagram(string1, string2))
        printf("TRUE\n");
    else
        printf("FALSE\n");
    return 0;
}