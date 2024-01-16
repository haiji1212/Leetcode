#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// 【1041】困于环中的机器人
// 在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。注意:
// 北方向 是y轴的正方向。
// 南方向 是y轴的负方向。
// 东方向 是x轴的正方向。
// 西方向 是x轴的负方向。
// 机器人可以接受下列三条指令之一：
// "G"：直走 1 个单位
// "L"：左转 90 度
// "R"：右转 90 度
// 机器人按顺序执行指令 instructions，并一直重复它们。
// 只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。
bool isRobotBounded(char* instructions) {
    int x = 0, y = 0;
    int dir = 1;    //北1 东2 南3 西4
    for(int i = 0; i < strlen(instructions); i ++){
        if(instructions[i] == 'L'){
            if(dir == 1)    dir = 4;
            else dir--;
        }else if(instructions[i] == 'R'){
            if(dir == 4)    dir = 1;
            else dir++;
        }
        if(instructions[i] == 'G' && dir == 1){
            y ++;
        }else if(instructions[i] == 'G' && dir == 2){
            x ++;
        }else if(instructions[i] == 'G' && dir == 3){
            y --;
        }else if(instructions[i] == 'G' && dir == 4){
            x --;
        }
    }
    if(x == 0 && y == 0)    return true;
    if(dir != 1)    return true;
    return false;
}
int main(void){
    char order[6] = "GGLLGG";
    int num = isRobotBounded(order);
    printf("%d\n", num);
    return 0;
}