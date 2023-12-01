#include<stdio.h>
#include<stdbool.h> //不使用该标准公共库会导致bool报错
#include<stdlib.h>
#include <string.h>
//【1047】删除字符串中的所有相邻重复项
// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
// 在 S 上反复执行重复项删除操作，直到无法继续删除。
// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
#define STACK_SIZE  20001
typedef struct{
    char* top;
    char* base;
    int stacksize;
}SqStack;

int StackInit(SqStack *s){
    s->base = (char*)malloc(STACK_SIZE * sizeof(char));
    if(!s->base) return 0;   //内存申请失败
    s->top = s->base;
    s->stacksize = STACK_SIZE;
    return 1;
}

int Push(SqStack *s, char str){
    if(s->top - s->base == s->stacksize)   return 0;   //栈满
    *(s->top++) = str;
    return 1;
}

int Pop(SqStack *s){
    if(s->top == s->base) return 0;   //栈空
    (s->top) --;
    return 1;
}

bool Empty(SqStack *s){
    if(s->top == s->base) return 1;
    else return 0;
}

int SizeStack(SqStack *s){
    return s->top - s->base;
}

char* removeDuplicates(char* s) {
    if(s == NULL)   return NULL;
    SqStack stack;
    if(!StackInit(&stack))    return 0;
    while(*s != '\0'){
        if(Empty(&stack)){  //栈为空，则直接入栈
            if(! Push(&stack, *s))   return 0;
        }else{  //栈不为空
            char top_val = *(stack.top - 1); //取栈顶元素
            if(*s == top_val){   //栈顶元素与该元素一致，则需出栈
                if( ! Pop(&stack))  return 0;
            }
            else{
                if(! Push(&stack, *s))   return 0;
            }
        }
        s ++;
    }
    int size = SizeStack(&stack);
    char* result = (char*)malloc((size + 1) * sizeof(char));
    if(result == NULL)  return 0;
    char* p = result;
    while (!Empty(&stack)) {
        *p = *(stack.top - 1);
        p++;
        Pop(&stack);
    }
    *p = '\0'; // 添加字符串终止符
    if(result == NULL)   return 0;
    int length = strlen(result);
    int first = 0, last = length - 1;
    while(first < last){
        char temp = result[first];
        result[first++] = result[last];
        result[last--] = temp;
    }
    return result;
}

int main()
{
    char str[20001] = {};
    scanf("%s", str);
    char* reDu = removeDuplicates(str);
    printf("%s\n", reDu);  
    return 0;
}