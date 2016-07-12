//
//  link.c
//  ReviewC
//
//  Created by zhangdong on 16/7/11.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#include "link.h"
#include <stdlib.h>

// 创建链表
List init_list(void) {
    
    List L;
    L = (position) malloc(sizeof(struct node));
    L -> next = NULL;
   
    return L;
}

// 判空
int is_null(List L) {
    
    return ((L->next) == NULL);
}

// 插入节点
void insert_node(position np, int value) {
    position nodeAddr;
    nodeAddr = (position)malloc(sizeof(struct node));
    nodeAddr->element = value;
    nodeAddr->next = np->next;
    np->next = nodeAddr;
}

// 删除链表
void delete_list(List L) {
    
    position np, next;
    np = L;
    do {
        next = np->next;
        free(np);
        np = next;
    } while (next != NULL);
}

//删除一个node
void delete_node(List L, position np) {
    position previous, next;
    next = np->next;
    previous = find_previous(L, np);
    
    if (previous != NULL) {
        previous->next = next;
        free(np);
    }
    else{
        printf("Error: np not in the list");
    }
}

/**
 *  寻找表的最后一个节点
 */
position find_last(List L) {
    position np;
    np = L;
    while (np->next != NULL) {
        np = np->next;
    }
    
    return np;
}

// 寻找np节点前面的节点
position find_previous(List L, position np) {
    position npTmp;
    npTmp = L;
    while (npTmp->next != NULL) {
        if (npTmp->next == np) {
            return npTmp;
        }
        npTmp = npTmp->next;
    }
    
    return NULL;
}

// 寻找value的节点
position find_value(List L, int value) {
    position np;
    np = L;
    while (np->next != NULL) {
        np = np->next;
        if (np->element == value) {
            return np;
        }
    }
    return NULL;
}

/**
 *  打印表
 */
void print_list(List L) {
    
    position np;
    if (is_null(L)) {
        printf("Empty List\n\n");
        return;
    }
    
    np = L;
    while (np ->next != NULL) {
        np = np -> next;
        printf("%p: %d \n", np, np -> element);
    }
    
    printf("\n");
}