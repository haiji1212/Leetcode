#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【682】棒球比赛
// 你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
// 比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：
// 整数 x - 表示本回合新获得分数 x
// "+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
// "D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
// "C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
// 请你返回记录中所有得分的总和。

int calPoints(char** operations, int operationsSize) {
    int stack[operationsSize];
    int top = 0;
    for(int i = 0; i < operationsSize; i ++){
        if(operations[i][0] == 'C'){
            top --;
            continue;
        }else if(operations[i][0] == 'D'){
            stack[top] = stack[top - 1] * 2;
            top ++;
            continue;
        }else if(operations[i][0] == '+'){
            stack[top] = stack[top - 1] + stack[top - 2];
            top++;
            continue;
        }
        stack[top ++] = atoi(operations[i]);
    }
    int count = 0;
    while(top > 0){
        count += stack[top - 1];
        top --;
    }    
    return count;
}

int main(){
    char *ops[5] = {"5", "2", "C", "D", "+"};
    int sum = calPoints(ops, 5);
    printf("%d\n", sum);
    return 0;
}
