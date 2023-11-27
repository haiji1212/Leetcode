#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//【541】反转字符串II
// 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

char* reverseStr(char* s, int k) {
    int length = strlen(s);  
    for(int i = 0 ; i < length; i += 2 * k){
        //当剩余字符少于 k 时， 全部反转
        k = i + k > length ? length - i : k;    

        int left = i;
        int right = i + k - 1;  //前 k 个字符
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
    return s;
}

int main()
{
    char str[100];
    scanf("%s", &str);
    int k = 2;
    char* ptr = reverseStr(str, k);
    while(*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
    return 0;
}