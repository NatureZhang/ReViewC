//
//  HashTable.h
//  ReviewC
//
//  Created by 张东 on 16/9/25.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>
#include <stdlib.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define UNSUCCESS 0

#define HASHSIZE 7
#define NULLKEY -32768

typedef int Status;
typedef struct {
    int *elem; // 数据元素存储地址，动态分配数组
    int count; // 当前数据元素个数
}HashTable;

// 构造
Status init_hashTable(HashTable *hashTable);

// 插入
void insert_hashTable(HashTable *hashTable, int data);

// 查找
int search_hashTable(HashTable *hashTable, int data);

// 输出
void print_hashTable(HashTable *hashTable);
#endif /* HashTable_h */
