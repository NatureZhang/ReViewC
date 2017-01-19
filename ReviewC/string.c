//
//  string.c
//  ReviewC
//
//  Created by zhangdong on 16/6/27.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#include "string.h"
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
