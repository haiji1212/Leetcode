#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【1275】找出井字棋的获胜者
// A 和 B 在一个 3 x 3 的网格上玩井字棋。
// 井字棋游戏的规则如下：
// 玩家轮流将棋子放在空方格 (" ") 上。
// 第一个玩家 A 总是用 "X" 作为棋子，而第二个玩家 B 总是用 "O" 作为棋子。
// "X" 和 "O" 只能放在空方格中，而不能放在已经被占用的方格上。
// 只要有 3 个相同的（非空）棋子排成一条直线（行、列、对角线）时，游戏结束。
// 如果所有方块都放满棋子（不为空），游戏也会结束。
// 游戏结束后，棋子无法再进行任何移动。
// 给你一个数组 moves，其中每个元素是大小为 2 的另一个数组（元素分别对应网格的行和列），它按照 A 和 B 的行动顺序（先 A 后 B）记录了两人各自的棋子位置。
// 如果游戏存在获胜者（A 或 B），就返回该游戏的获胜者；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。
// 你可以假设 moves 都 有效（遵循井字棋规则），网格最初是空的，A 将先行动。

char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    int flag[3][3] = {0};
    for(int i = 0; i < movesSize; i ++){
        int x = moves[i][0], y = moves[i][1];
        if(i & 1)   flag[x][y] --;  //B为-1
        else flag[x][y] ++; //A为1
    }
    int sum1 = flag[0][0] + flag[1][1] + flag[2][2];
    int sum2 = flag[0][2] + flag[1][1] + flag[2][0];
    if(sum1 == 3 || sum2 == 3)  return "A";
    else if(sum1 == -3 ||sum2 == -3)    return "B";
    for(int i = 0; i < 3; i ++){
        int sum3 = flag[i][0] + flag[i][1] + flag[i][2];
        int sum4 = flag[0][i] + flag[1][i] + flag[2][i];
        if(sum3 == 3 || sum4 == 3)  return "A";
        else if(sum3 == -3 ||sum4 == -3)    return "B";      
    }
    return movesSize == 9 ? "Draw" : "Pending";
}
