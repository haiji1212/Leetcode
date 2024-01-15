#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【709】转换成小写字母
// 给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。

char* toLowerCase(char* s) {
    char* p = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    char* res = p;
    for(int i = 0; i < strlen(s); i ++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            *p = s[i] + 'a' - 'A';
        }else{
            *p = s[i];
        }
        p ++;
    }
    *p = '\0';
    return res;
}

int main(){
    char str[100] = "aBcDeFG";
    printf("%s\n", &str);
    char* s = toLowerCase(str);
    printf("%s\n", s);
    return 0;
}
