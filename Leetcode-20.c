#include<stdio.h>
#include<stdbool.h> //不使用该标准公共库会导致bool报错
#include<stdlib.h>
#include <string.h>
//【20】有效的括号
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
// 有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。每个右括号都有一个对应的相同类型的左括号。
#define STACK_SIZE  10001
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

bool isValid(char* s) {
    int length = strlen(s);
    if( length == 0)    return 1;
    if( length % 2 != 0)    //如果是奇数位个数，则必然无效
        return 0;
    SqStack stack;
    if(!StackInit(&stack))    return 0;
    while(*s != '\0'){
        if(*s == '(' || *s == '[' || *s == '{'){
            if(! Push(&stack, *s))   return 0;
        }
        else if(*s == ')' || *s == ']' || *s == '}'){
            if(Empty(&stack))   return 0;     //栈为空时输入右括号，则必然无效
            char top = *(stack.top - 1);
            if((*s == ')' && top == '(') || (*s == ']' && top == '[') || (*s == '}' && top == '{')){
                if( ! Pop(&stack))  return 0;
            }    
            else    return 0;
        }
        s ++;
    }
    return Empty(&stack);
}

int main()
{
    char str[10001] = {};
    scanf("%s", str);
    if(isValid(str))    printf("TRUE\n");
    else    printf("FALSE\n");
    return 0;
}