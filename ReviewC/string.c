//
//  string.c
//  ReviewC
//
//  Created by zhangdong on 16/6/27.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#include "string.h"
#include <stdbool.h>
#include <string.h>
char *myStrCopy(char *strCpy, const char *strSrc) {
    
    if (strCpy == NULL || strSrc == NULL) {
        return NULL;
    }
    
    if (strCpy == strSrc) {
        return strCpy;
    }
    
    char *tmpStr = strCpy;
    while ((*tmpStr++ = *strSrc++) != '\0'){
        
    };
        return tmpStr;
}

// 长度
int myStrlen(const char *strSrc) {
    
    int count = 0;
    while (*strSrc++ != '\0') {
        count ++;
    }
    
    return count;
}

// 字符串拼接
char *myStrcat(char *dst, const char *src) {
    
    char *cp = dst;
    
    while (*cp) {
        cp ++;
    }
    
    while ((*cp++ = *src++)) {
        
    }
    
    return dst;
    
}

// 比较
int	 myStrcmp(const char *str1, const char *str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        ++str1;
        ++str2;
    }
    
    return *str1 - *str2;
}

void myStrRev(char *str) {
    
    char temp, *end = str + myStrlen(str) - 1;
    while (end > str) {
        temp = *str;
        *str = *end;
        *end = temp;
        
        --end;
        ++str;
    }
}

// 小写
void strlower(char *strSrc) {
    
}

// 大写
void strupper(char *strSrc) {
    
}

//辅助方法 判断是否数字字符
bool isDigit(char ch) {
    return '0'<=ch && ch<='9';
}

typedef enum {VALID, INVALID} ResType; //返回的结果类型
ResType g_rtRes = VALID;

// 字符转Int
int myStrToInt(const char *str) {
    
    unsigned int iCur, iMax;
    int sign;
    const char *p;
    
    // 判断参数是否合法
    if (!str || strlen(str) <= 0) {
        g_rtRes = INVALID;
        return 0;
    }
    
    // 去掉前面空格
    for (p = str; ' ' == *p; p++) {
        
    }
    
    // 判断正负号
    sign = 1;
    iMax = ~(1 << (8 * sizeof(int) - 1));
    if (*p == '+') {
        p ++;
    }
    else if (*p == '-') {
        p ++;
        sign = -1;
        iMax = ~iMax;
    }
    
    // 首位不是数字，输入非法
    if (!isDigit(*p)) {
        g_rtRes = INVALID;
        return 0;
    }
    
    // 首位是0，特殊处理
    if ('0' == *p) {
        return 0;
    }
    
    // 累和
    for (iCur = 0; isDigit(*p) && iCur <= iMax; p++) {
        iCur = iCur * 10 + (*p - '0');
    }
    
    // 返回结果
    if(iCur <= iMax) {
        return (int)(sign * iCur);
    } else {
        g_rtRes = INVALID;
        return 0;
    }
    
}

// 替换字符串中的空格为 %20 从后向前
void replaceBlank(char string[], int length) {
    
    if (string == NULL || length <= 0) {
        return;
    }

    int blank = 0;
    int nLength = 0;
    
    for (int i = 0; i < length; i ++) {
        if (string[i] == ' ') {
            blank ++;
        }
    }
    
    nLength = length + blank * 2;
    
    for (int j = length; j >= 0; j--) {
        
        if (string[j] != ' ') {
            string[nLength] = string[j];
            nLength --;
        }
        else {
            string[nLength --] = '0';
            string[nLength --] = '2';
            string[nLength --] = '%';
        }
    }
}

// 判断有效的ip地址
int isIPValid(char *ip ){
    
    int p[4] ={0,0,0,0};
    int len = myStrlen(ip);
    int j = 0;
    int head = 0;
    for(int i = 0; i < len; i++){
        if(ip[i] == '.' || i == len -1 ){
            /*分割符*/
            if(p[j] >= 0 && p[j] <= 255){
                printf("%d\n", p[j]);
                j ++;
                head = 0;
            }else{
                return 0;
            }
            
        }else{
            
            if (head == 0 && ip[i] == '0') {
                return 0;
            }
            else {
                head = 1;
            }
            
            int d = ip[i] - '0';
            if(d > 9 || d < 0){
                return 0;
            }else{
                p[j] = p[j] * 10 + d;
            }
        }
    }
    return 1;
    
}








































