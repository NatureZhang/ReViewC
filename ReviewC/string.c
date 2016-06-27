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