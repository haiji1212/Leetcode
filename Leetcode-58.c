#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【58】最后一个单词的长度
// 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
// 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

int lengthOfLastWord(char* s) {
    char* p = s;
    int count = 0, num = 0, flag = 0;
    while(*p != '\0'){
        p++;
        count ++;
    }
    p --;
    while(*p == ' '){
        p --;
        flag ++;
    }
    while(*p != ' '){
        p--;
        num++;
        if((num + flag) == count)
            return num;
    }
    return num;
}

int main(){
    char str[100] = "ab c cab ";
    printf("%s\n", &str);
    int countNum = lengthOfLastWord(str);
    printf("The last word has %d numbers\n", countNum);
    return 0;
}
