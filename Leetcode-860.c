#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// 【860】柠檬水找零
// 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
// 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。
// 你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
// 注意，一开始你手头没有任何零钱。
// 给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

bool lemonadeChange(int* bills, int billsSize) {
    int count_5 = 0, count_10 = 0, count_20 = 0;
    for(int i = 0; i < billsSize; i ++){
        if(bills[i] == 5){
            count_5 ++;
        }else if(bills[i] == 10){
            count_10 ++;
            count_5 --;
            if(count_5 < 0)
                return false;
        }else if(bills[i] == 20){
            count_20 ++;
            if(count_10 > 0){
                count_10 --;
                count_5 --;
                if(count_5 < 0)
                    return false;
            }
            else{
                count_5 -= 3;
                if(count_5 < 0)
                    return false;
            }
        }
    }
    return true;
}

int main(){
    // int accounts[5] = {5,5,10,10,20};   //{5,5,5,10,20};
    int accounts[] = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    printf("result is %d\n", lemonadeChange(accounts, sizeof(accounts) / sizeof(accounts[0])));
    return 0;
}