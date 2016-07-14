//
//  queue.c
//  ReviewC
//
//  Created by zhangdong on 16/7/14.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>

// 初始队列
queue init_queue(void) {
    
    queue hnp;
    hnp = (queue)malloc(sizeof(struct HeadNode));
    hnp->next = NULL;
    hnp->end = NULL;
    return hnp;
}

// 删除队列
void delete_queue(queue q) {
    while (!is_emptyq(q)) {
        dequeue(q);
    }
    free(q);
}

// 入队
void enqueue(queue q, int value) {
    qPosition np, oldEnd;
    oldEnd = q->end;
    
    np = (qPosition)malloc(sizeof(struct qNode));
    np->element = value;
    np->next = NULL;
    if (oldEnd) {
        oldEnd->next = np;
    }
    else {
        q->next = np;
    }
    
    q->end = np;
}

// 出队
int dequeue(queue q) {
    int element;
    qPosition first, newFrist;
    if (is_emptyq(q)) {
        printf("dequeue() on an empty queue");
        exit(1);
    }
    else{
        first = q->next;
        element = first->element;
        newFrist = first->next;
        q->next = newFrist;
        free(first);
        return element;
    }
}

// 判队空
int is_emptyq(queue q) {
    
    return q->next == NULL;
}