//
//  main.c
//  ReviewC
//
//  Created by zhangdong on 16/6/27.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

/*
 Review 指针 数组 字符串 结构体
 */

#include <stdio.h>
#include <string.h>
#include "string.h"

#define STR_LEN 30

void testMyStrCopy() {
    
    char *strSrc = "www.baidu.com";
    char strCpy[STR_LEN];
    memset(strCpy, 0, STR_LEN);
    
    printf("strCpy = %s\n", strCpy);
    myStrCopy(strCpy, strSrc);
    printf("strCpy = %s\n", strCpy);
    
    printf("strlen = %d \n", myStrlen(strSrc));
    
    char *str2 = ".cn";
    printf("str = %s\n", myStrcat(strSrc, str2));
}

int main(int argc, const char * argv[]) {
    
    testMyStrCopy();
    
    return 0;
}

