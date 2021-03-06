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
char *myStrcat(char *dst, const char *src);

// 长度
int myStrlen(const char *strSrc);

// 比较
int	 myStrcmp(const char *str1, const char *str2);

// 翻转
void myStrRev(char *str);

// 小写
void strlower(char *strSrc);

// 大写
void strupper(char *strSrc);

// 字符串转数字
int myStrToInt(const char *str);

// 替换字符串中的空格为 %20
void replaceBlank(char string[], int length);

// 判断是否为有效的ip地址
int isIPValid(char *ip );

#endif /* string_h */
