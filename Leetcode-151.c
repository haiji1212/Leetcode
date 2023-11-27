#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//【151】反转字符串中的单词
// 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
// 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
// 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
void removeNULL(char* s){  //移除多余空格
    int first = 0;
    int last = strlen(s) - 1;
    while(s[first] == ' ')  first++;    //去掉前面多余空格
    while(s[last] == ' ')   last--;     //去掉后面多余空格
    int slow = 0;
    for(int i = first; i <= last; i++){
        if(s[i] == ' ' && s[i + 1] == ' '){
            continue;
        }
        s[slow++] = s[i];
    }
    s[slow] = '\0'; 
}
void reverseALL(char* s, int first, int last){  //反转全部字符
    while(first < last){
        char temp = s[first];
        s[first ++] = s[last];
        s[last --] = temp;
    }
}
char* reverseWords(char* s) {
    removeNULL(s);
    // printf("removeNULL:\n%s has %d words\n", s, strlen(s));
    reverseALL(s, 0, strlen(s) - 1);
    // printf("reverseALL:\n%s has %d words\n", s, strlen(s));   
    //以空格为间隔分割单词，将各个单词反转
    int slow = 0;
    for(int i = 0; i <= strlen(s); i ++){
        if(s[i] == ' ' || s[i] == '\0'){
            reverseALL(s, slow, i - 1);
            slow = i + 1;
        }      
    }
    return s;
}

int main()
{
    char string[100] = " hello  tcxh  ";
    printf("ORIGIN:\n%s has %d words\n", string, strlen(string));
    char* ptr = reverseWords(string);
    printf("FINAL:\n%s has %d words\n", ptr, strlen(ptr));
    return 0;
}