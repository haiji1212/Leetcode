#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//【344】反转字符串
// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

void reverseString(char* s, int sSize) {
    if(s == NULL || sSize <= 1)
        return;
    for(int i = 0, j = sSize - 1; i <= j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main()
{
    char str[] = "Hello";
    printf("%s has %d words\n", str, strlen(str));
    reverseString(str, strlen(str));
    printf("%s has %d words\n", str, strlen(str));
    return 0;
}