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
char *myStrcat(char *dest, const char *strSrc) {
    
    return NULL;
}


//
//// 比较
//int	 myStrcmp(const char *str1, const char *str2) {
//    
//}

// 小写
void strlower(char *strSrc) {
    
}

// 大写
void strupper(char *strSrc) {
    
}