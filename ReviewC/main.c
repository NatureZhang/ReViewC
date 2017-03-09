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
#include "search.h"
#include "link.h"
#include "stack.h"
#include "queue.h"
#include "HashTable.h"
#include "HashTable_new.h"
#define STR_LEN 30

void myStr() {
    
//    char *strSrc = "www.baidu.com";
//    char a[80];
    
    // fuck 怎么不管用
//    printf("copy str:%s \n", myStrCopy(a,));
    
//    printf("strlen = %d \n", myStrlen(strSrc));
//    
//    char *str2 = ".cn";
//    printf("str = %s\n", myStrcat(strSrc, str2));
    
    char dst[20] = "zhangdong, ";
    char *catStr = myStrcat(dst, "hello");
    printf("%s\n", catStr);
    
    int strCmp = myStrcmp(dst, "zhangdong");
    printf("%d \n", strCmp);
    
    myStrRev(catStr);
    printf("%s\n", catStr);
    
    int strInt = myStrToInt("-2345678");
    printf("%d\n", strInt);
    
    char string[] = "we are happy.";
    replaceBlank(string, 14);
    printf("%s\n", string);
    
    char *ip = "127.068.1.10";
    printf("%d\n", isIPValid(ip));
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

void search() {
    int a[] = {2, 4, 7, 3, 8, 1};
    int position = binarySearch(a, 6, 7);
    printf("查找元素位于 %d 位置\n", position);
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

void queuetest(){
    
    int a;
    int i;
    queue queue;
    queue = init_queue();
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 8);
    printf("Queue is null?%d\n", is_emptyq(queue));
    for (i = 0; i < 3; i ++) {
        a = dequeue(queue);
        printf("dequeue:%d\n", a);
    }
    
    printf("Queue is null?%d\n", is_emptyq(queue));
    delete_queue(queue);
}

void hashTable(){
    
    int result;
    HashTable hashTable;
    int a[HASHSIZE] = {13, 29, 27, 28, 26, 30, 38};
    
    init_hashTable(&hashTable);
    
    for (int i = 0; i < HASHSIZE; i++) {
        insert_hashTable(&hashTable, a[i]);
    }
    
    print_hashTable(&hashTable);
    
    int search = 28;
    
    result = search_hashTable(&hashTable, search);
    if (result == -1) {
        printf("对不起，没有找到");
    }
    else{
        printf("%d在哈希表中的位置是：%d\n", search, result);
    }
}
//void hashTable_new() {
//    hashTable_new * hashtable = hashtable_init(10);
//    hashtable_put(hashtable, "a", "1");
//    hashtable_put(hashtable, "b", "2");
//    hashtable_put(hashtable, "c", "3");
//    hashtable_put(hashtable, "d", "4");
//    hashtable_put(hashtable, "e", "5");
//    hashtable_put(hashtable, "f", "6");
//    hashtable_put(hashtable, "g", "7");
//    hashtable_put(hashtable, "h", "8");
//    hashtable_put(hashtable, "i", "9");
//    hashtable_put(hashtable, "j", "10");
//    hashtable_put(hashtable, "k", "11");
//    hashtable_put(hashtable, "l", "12");
//    hashtable_put(hashtable, "f", "8");
//    hashtable_remove(hashtable, "f");
//    hashtable_print(hashtable);
//
//}

/// 人必须学会，放下无用的恐惧，将全部精力，专注于事情本身

int main(int argc, const char * argv[]) {
    
    myStr();
    
//    sort();
    
//    search();
    
//    list();
    
//    stacktest();
//    queuetest();
    
//    hashTable();
    
    
    
    return 0;
}

