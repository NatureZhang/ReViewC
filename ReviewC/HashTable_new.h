//
//  HashTable_new.h
//  ReviewC
//
//  Created by 张东 on 16/9/30.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#ifndef HashTable_new_h
#define HashTable_new_h

#include <stdio.h>

typedef struct HashNode{
    char* key;
    char* value;
    HashNode* next; //相同hash取下一个节点
} HashNode;


typedef struct Hashtable{
    int size;
    int item_size;
    HashNode* head;
} Hashtable;


/*初始化*/
Hashtable* hashtable_init(int size);

/*添加一个*/
void hashtable_put(Hashtable *hashtable, char* key, char* value);

/*获取一个*/
char* hashtable_get(Hashtable *hashtable, char* key);

/*删除一个*/
void hashtable_remove(Hashtable *hashtable, char* key);

/*销毁*/
void hashtable_destroy(Hashtable *hashtable);

/*打印*/
void hashtable_print(Hashtable *hashtable);

/*hash算法*/
int hash(char* key, int size);

#endif /* HashTable_new_h */
