//
//  string.h
//  ReviewC
//
//  Created by zhangdong on 16/6/27.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#ifndef string_h
#define string_h

#include <stdio.h>

// 字符串拷贝
char *myStrCopy(char *strCpy, const char *strSrc);

// 字符串拼接
char *myStrcat(char *dest, const char *strSrc);

// 长度
int myStrlen(const char *strSrc);

// 比较
int	 myStrcmp(const char *str1, const char *str2);

// 小写
void strlower(char *strSrc);

// 大写
void strupper(char *strSrc);

#endif /* string_h */
