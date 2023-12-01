#include<stdio.h>
#include<stdbool.h> //不使用该标准公共库会导致bool报错
#include<stdlib.h>
#include <string.h>
//【1047】删除字符串中的所有相邻重复项
// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
// 在 S 上反复执行重复项删除操作，直到无法继续删除。
// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
char* removeDuplicates(char* s) {
    int size = strlen(s);
    char* stack = (char*)malloc(100 * sizeof(char));    //实际提交需要注意长度限制
    int top;
    while(*s != '\0'){
        if(top == 0){    //栈为空
            stack[top++] = *s;
        }else{
            if(*s == stack[top - 1]){
                top --;
            }
            else{
                stack[top++] = *s; 
            }
        }
        s ++;
    }
    stack[top] = '\0';
    return stack;
}

int main()
{
    char str[20001] = {};
    scanf("%s", str);
    char* reDu = removeDuplicates(str);
    printf("%s\n", reDu);  
    return 0;
}