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
#include "sort.h"
#define STR_LEN 30

void testMyStrCopy() {
    
    char *strSrc = "www.baidu.com";
    char a[80];
    
    // fuck 怎么不管用
//    printf("copy str:%s \n", myStrCopy(a,));
    
//    printf("strlen = %d \n", myStrlen(strSrc));
//    
//    char *str2 = ".cn";
//    printf("str = %s\n", myStrcat(strSrc, str2));
    
}

void sort() {
    
    int a[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
//    bubleSort(a, 10);
    
//    quickSort(a, 0, 9);
    
//    quickSort2(a, 0, 9);
    
//    selectSort(a, 10);
    
//    insertionSort(a, 10);
    int temp[10];
    mergeSort(a, 0, 9, temp);
    
    for (int i = 0; i < 10; i ++) {
        printf("%d ", a[i]);
    }
    
    
    printf("\n");
}


int main(int argc, const char * argv[]) {
    
//    testMyStrCopy();
    
    sort();
    
    return 0;
}

