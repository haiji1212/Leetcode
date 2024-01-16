#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【657】机器人能否返回原点
// 在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。
// 移动顺序由字符串 moves 表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。
// 如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
// 注意：机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。
bool judgeCircle(char* moves) {
    int count[4] = {0};
    char* ptr = moves;
    while(*ptr != '\0'){
        switch(*ptr){
            case 'R':
                count[0] ++;
                break;
            case 'L':
                count[1] ++;
                break;
            case 'U':
                count[2] ++;
                break;
            case 'D':
                count[3] ++;
                break;
            default:
                break;
        }
        ptr++;
    }
    if(count[0] == count[1] && count[2] == count[3])    return true;
    else return false;
}

int main(){
    char actions[2] = "LL";
    printf("%d\n", judgeCircle(actions));
    return 0;
}
