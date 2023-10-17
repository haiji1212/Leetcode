#include <stdio.h>

// 【13】罗马数字转整数
// 给定一个罗马数字，将其转换成整数。
int romanToInt(char *s);

int romanToInt(char *s)
{
    char *p = s;
    int number = 0;
    while (*(s) != '\0')
    {
        if (*s == 'I')
        {
            if (s[1] == 'V')
            {
                s++;
                number += 4;
            }
            else if (s[1] == 'X')
            {
                s++;
                number += 9;
            }
            else
                number += 1;
        }
        else if (*s == 'V')
            number += 5;
        else if (*s == 'X')
        {
            if (s[1] == 'L')
            {
                s++;
                number += 40;
            }
            else if (s[1] == 'C')
            {
                s++;
                number += 90;
            }
            else
                number += 10;
        }
        else if (*s == 'L')
            number += 50;
        else if (*s == 'C')
        {
            if (s[1] == 'D')
            {
                s++;
                number += 400;
            }
            else if (s[1] == 'M')
            {
                s++;
                number += 900;
            }
            else
                number += 100;
        }
        else if (*s == 'D')
            number += 500;
        else if (*s == 'M')
            number += 1000;
        s++;
    }
    return number;
}

int main()
{
    char key[] = "MCMXCIV";
    char *str = key;
    int num = 0;
    num = romanToInt(str);
    printf("num is %d\n", num);
    return 0;
}