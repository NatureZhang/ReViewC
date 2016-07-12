//
//  link.h
//  ReviewC
//
//  Created by zhangdong on 16/7/11.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#ifndef link_h
#define link_h

/**
 *  表是一个有序的元素集合，表存储为 分散 的节点，每个节点包含有一个元素，以及一个指向下一个元素的指针
 *  表的功能与数组类似，数组也是有序元素集合，但数组在内存中为一段连续内存，而表的每个节点在内存中是离散的
    可以通过跳过固定的内存长度来寻找某个编号的元素。但在表中，我们必须沿着指针遍历查询。数组有固定大小，表可以根据运行情况
    插入或者删除节点，动态更改大小。
 */
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
