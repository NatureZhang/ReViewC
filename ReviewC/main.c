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
#include "link.h"
#include "stack.h"
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
//    int temp[10];
//    mergeSort(a, 0, 9, temp);
    
    shellSort(a, 10);
    for (int i = 0; i < 10; i ++) {
        printf("%d ", a[i]);
    }
    
    
    printf("\n");
}

void list(){
    List list;
    position np;
    
    int i;
    int a[] = {1, 3, 5, 7, 9};
    list = init_list();
    print_list(list);
    
    for (i = 4; i >= 0; i--) {
        insert_node(list, a[i]);
    }
    print_list(list);
    
    np = find_value(list, 5);
    delete_node(list, np);
    print_list(list);
    
}

void stacktest(){
    ElementTy a;
    int i;
    stack sk;
    sk = init_stack();
    push(sk, 1);
    push(sk, 2);
    push(sk, 8);
    printf("stack is null? %d\n", is_empty(sk));
    for (i = 0; i < 3; i ++) {
        a = pop(sk);
        printf("pop: %d\n", a);
    }
    
    printf("stack is null? %d \n", is_empty(sk));
    delete_stack(sk);
}

int main(int argc, const char * argv[]) {
    
//    testMyStrCopy();
    
//    sort();
    
//    list();
    
    stacktest();
    
    return 0;
}

