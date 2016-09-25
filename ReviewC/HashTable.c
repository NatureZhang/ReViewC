//
//  HashTable.c
//  ReviewC
//
//  Created by 张东 on 16/9/25.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#include "HashTable.h"

int m = 0; //表长

// 构造
Status init_hashTable(HashTable *hashTable) {
   
    int i;
    m = HASHSIZE;
    
    hashTable->elem = (int *)malloc(m * sizeof(int));
    
    hashTable->count = m;
    
    for (i = 0; i < m; i++) {
        hashTable->elem[i] = NULLKEY;
    }
    
    return OK;
}

// 哈希函数 除留余数法
int Hash(int data) {
    return data % m;
}

// 插入
void insert_hashTable(HashTable *hashTable, int data) {
    
    int hashAddress = Hash(data); // 求哈希地址
    
    // 发生冲突
    while (hashTable->elem[hashAddress] != NULLKEY) {
        // 利用开放定值线性探测法解决冲突
        
        hashAddress = Hash(++hashAddress);//yi
    }
    
    // 插入值
    hashTable->elem[hashAddress] = data;
    
}

// 查找
int search_hashTable(HashTable *hashTable, int data) {
    
    int hashAddress = Hash(data);
    
    while (hashTable->elem[hashAddress] != data) {
        hashAddress = Hash(++hashAddress);
        
        if (hashTable->elem[hashAddress] == NULLKEY || hashAddress == Hash(data)) {
            return -1;
        }
    }
    
    return hashAddress;
    
}

// 输出
void print_hashTable(HashTable *hashTable) {
    
    int i;
    printf("\n**********展示结果**********\n");
    
    for (i=0;i<hashTable->count;i++)
    {
        printf("%d ",hashTable->elem[i]);
    }
    
    printf("\n**********展示完毕**********\n");
    
}