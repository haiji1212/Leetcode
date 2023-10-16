#include<stdio.h>
#include<stdbool.h> //不使用该标准公共库会导致bool报错
#include<math.h>

//【9】回文数
// 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

bool isPalindrome(int x);

bool isPalindrome(int x)
{
    if(x < 0){  //小于0，则一定不是回文整数

        return false;
    }
    else if((x / 10) == 0){    //一位数，是回文数
        return true;
    }
    else{   //两位数以上
        int real_num = x;
        int num = 0;
        int i = 0;
        while( ((x % 10) > 0) || ((x / 10) > 0)){
            num *= 10;
            num += (x % 10);
            x /= 10;
            i ++;
        }

        if(num == real_num)
            return true;
        else
            return false;
    }
}

int main()
{
    int number;
    printf("please input a number:\n");
    scanf("%d", &number);
    if(isPalindrome(number) == 1)
        printf("TRUE!\n");
    else
        printf("FLASE!\n");
    return 0;
}