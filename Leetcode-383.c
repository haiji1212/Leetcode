#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//【383】赎金信
// 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
// 判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。

bool canConstruct(char* ransomNote, char* magazine) {
    int ransomSize = strlen(ransomNote);
    int magzineSize = strlen(magazine);
    if(ransomSize > magzineSize)    //ransom长度大于magzine，必定不满足
        return 0;
    int Table[26] = {0};
    char* p = magazine;
    while(*p != '\0'){
        Table[*p - 'a'] ++;
        p++;
    }
    p = ransomNote;
    while(*p != '\0'){
        Table[*p - 'a'] --;
        if(Table[*p - 'a'] < 0)
            return 0;
        p++;
    }   
    return 1;
}

int main()
{
    char string1[10] = "ab";
    char string2[10] = "bcg";
    if(canConstruct(string1, string2))
        printf("TRUE\n");
    else
        printf("FALSE\n");
    return 0;
}