#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【459】重复的字符串
// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);

    for (int len = 1; len <= n/2; len++) {
        if (n % len == 0) {
            char substr[len+1];
            strncpy(substr, s, len);
            substr[len] = '\0';
            
            bool repeated = true;
            
            for (int i = len; i <= n-len; i += len) {
                if (strncmp(s + i, substr, len) != 0) {
                    repeated = false;
                    break;
                }
            }
            
            if (repeated) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    char s[] = "abcabcabc"; 
    bool result = repeatedSubstringPattern(s);  
    if (result) {
        printf("The string can be formed by repeating a substring.\n");
    } else {
        printf("The string cannot be formed by repeating a substring.\n");
    } 
    return 0;
}


