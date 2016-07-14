//
//  queue.h
//  ReviewC
//
//  Created by zhangdong on 16/7/14.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#ifndef queue_h
#define queue_h

/**
 *  队列，有序的数据元素集合，先进先出
 *  队列支持两个操作，队首的元素离开队列（dequeue），新元素加入队列（enqueue）
 */

#include <stdio.h>

typedef struct qNode *qPosition;

typedef struct HeadNode *queue;

struct qNode {
    int element;
    qPosition next;
};

struct HeadNode {
    int element;
    qPosition next;
    qPosition end;
};

queue init_queue(void);
void delete_queue(queue);
void enqueue(queue, int);
int dequeue(queue);
int is_emptyq(queue);
#endif /* queue_h */
