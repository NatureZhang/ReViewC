//
//  HashTable_new.c
//  ReviewC
//
//  Created by 张东 on 16/9/30.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#include "HashTable_new.h"
#include <stdio.h>
#include <stdlib.h>


/*hash算法*/
int hash(char* key, int size){
    int rect = 0;
    while (*key != '\0')
    {
        rect += *key;
        key++;
    }
    return rect%size;
}

/*初始化hashtable*/
Hashtable* hashtable_init(int size){
    Hashtable* hashtable = (Hashtable*)calloc(1, sizeof(Hashtable));
    hashtable->size = size;
    hashtable->item_size = 0;
    HashNode* head = (HashNode *)calloc(size, sizeof(HashNode));
    hashtable->head = head;
    return hashtable;
}

/*添加一个*/
void hashtable_put(Hashtable *hashtable, char* key, char* value){
    int index = hash(key, hashtable->size);
    
    HashNode *hashNode = hashtable->head + index;
    
    while (1)
    {
        if (hashNode->key == NULL || *key == *(hashNode->key))
        {
            if (hashNode->key == NULL)
            {
                hashtable->item_size = hashtable->item_size + 1;
            }
            hashNode->key = key;
            hashNode->value = value;
            return;
        }
        if (hashNode->next != NULL){
            hashNode = hashNode->next;
        }
        else{
            HashNode *newNode = (HashNode*)calloc(1, sizeof(HashNode));
            newNode->key = key;
            newNode->value = value;
            hashNode->next = newNode;
            hashtable->item_size = hashtable->item_size + 1;
            return;
        }
    }
}

/*获取一个*/
char* hashtable_get(Hashtable *hashtable, char* key){
    int index = hash(key, hashtable->size);
    HashNode *hashNode = hashtable->head + index;
    while (hashNode != NULL)
    {
        if (hashNode->key != NULL&&*key == *(hashNode->key))
        {
            return hashNode->value;
        }
        hashNode = hashNode->next;
    }
    return NULL;
}

/*删除一个*/
void hashtable_remove(Hashtable *hashtable, char* key){
    int index = hash(key, hashtable->size);
    HashNode *hashNode = hashtable->head + index;
    HashNode *temp = hashNode;
    while (hashNode != NULL)
    {
        if (*key == *(hashNode->key))
        {
            if ((hashtable->head + index) == hashNode)
            {
                hashNode->key = NULL;
                hashNode->value = NULL;
            }
            else
            {
                temp->next = hashNode->next;
                free(hashNode);
            }
            hashtable->item_size = hashtable->item_size - 1;
            return;
        }
        temp = hashNode;
        hashNode = hashNode->next;
    }
    return;
}


/*销毁*/
void hashtable_destroy(Hashtable *hashtable){
    HashNode *head = hashtable->head;
    for (int index = 0; index < hashtable->size; index++)
    {
        HashNode *next = head->next;
        while (next != NULL)
        {
            HashNode *temp = next;
            next = next->next;
            free(temp);
        }
        head++;
    }
    free(hashtable->head);
    free(hashtable);
}

/*打印*/
void hashtable_print(Hashtable *hashtable){
    HashNode *head = hashtable->head;
    for (int index = 0; index < hashtable->size; index++)
    {
        printf("index:%d\t", index);
        if (head->key!=NULL)
        {
            printf("%s:%s\t", head->key, head->value);
        }
        
        HashNode *next = head->next;
        while (next != NULL)
        {
            if (next->key != NULL)
            {
                printf("%s:%s\t", next->key, next->value);
            }
            next = next->next;
        }
        printf("\n");
        head++;
    }
}
