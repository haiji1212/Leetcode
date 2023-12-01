#include<stdio.h>
#include<stdbool.h> //不使用该标准公共库会导致bool报错
#include<stdlib.h>
#include <string.h>
//【150】逆波兰表达式求值
// 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
// 请你计算该表达式。返回一个表示表达式值的整数。
// 注意：
// 有效的算符为 '+'、'-'、'*' 和 '/' 。每个操作数（运算对象）都可以是一个整数或者另一个表达式。两个整数之间的除法总是 向零截断 。表达式中不含除零运算。
// 输入是一个根据逆波兰表示法表示的算术表达式。答案及所有中间计算结果可以用 32 位 整数表示。
_Bool isnumber(char* str) {
    return strlen(str) > 1 || (str[0] >= '0' && str[0] <= '9');
}
int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(sizeof(int) * tokensSize);
    int stacktop = 0;
    for(int i = 0; i < tokensSize; i ++){
        char* token = tokens[i];
        if(isnumber(token)){
            stack[stacktop++] = atoi(tokens[i]);    //atoi可以将字符串转换为整数
        }else{
            int num1 = stack[--stacktop];
            int num2 = stack[--stacktop];
            switch(token[0]){
                case '+':
                    stack[stacktop++] = num2 + num1;
                    break;
                case '-':
                    stack[stacktop++] = num2 - num1;
                    break;
                case '*':
                    stack[stacktop++] = num2 * num1;
                    break;
                case '/':
                    stack[stacktop++] = num2 / num1;
                    break;
            }
        }
    }
    int val = stack[stacktop - 1];
    free(stack);
    return val;
}

int main()
{
    char* str[] = {"2", "1", "+", "3", "*"};
    int size = sizeof(str) / sizeof(str[0]);
    printf("is %d\n", evalRPN(str, size));
    return 0;
}