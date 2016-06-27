//
//  main.c
//  ReviewC
//
//  Created by zhangdong on 16/6/27.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

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
    
}

int main(int argc, const char * argv[]) {
    
    testMyStrCopy();
    
    return 0;
}

