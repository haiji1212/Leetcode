#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// 【1491】去掉最低工资和最高工资后的工资平均值
// 给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。
// 请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。
double average(int* salary, int salarySize) {
    int sum = 0;
    int max = salary[0], min = salary[0];
    for(int i = 0; i < salarySize; i++){
        max = salary[i] > max ? salary[i] : max;
        min = salary[i] < min ? salary[i] : min;
    }
    for(int i = 0; i < salarySize; i++){
        if(salary[i] != max && salary[i] != min){
            sum += salary[i];
        }
    }
    double res = (double)sum / (salarySize - 2);
    return res;
}

int main(){
    int num[6] = {6000,5000,4000,3000,2000,1000};
    printf("average is %f\n",average(num, 6));
    return 0;
}