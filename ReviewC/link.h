//
//  link.h
//  ReviewC
//
//  Created by zhangdong on 16/7/11.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#ifndef link_h
#define link_h

#include <stdio.h>

typedef struct node *List;
typedef struct node *position;

/**
 *  node 节点
 */
struct node {
    int element;
    position next;
};

/**
 *  操作
 */
// 初始链表
List init_list(void);

// 链表判空
int is_null(List);

// 插入节点
void insert_node(position, int);

// 删除节点
void delete_node(List, position);

// 删除链表
void delete_list(List);

// 寻找最后一个节点
position find_last(List);

// 寻找值为value的节点
position find_value(List, int);

// 寻找position的前一个节点
position find_previous(List, position);

// 打印链表
void print_list(List);

#endif /* link_h */
