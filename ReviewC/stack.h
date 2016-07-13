//
//  stack.h
//  ReviewC
//
//  Created by zhangdong on 16/7/13.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#ifndef stack_h
#define stack_h
/**
 *  栈 最显著的特征是LIFO（后进先出）。栈中的每个元素称为一个frame。
    栈支持三个操作pop，top， push。
    pop 取出栈中最上层元素
    top 查看栈的最上层元素
    push 将一个新的元素放在栈的最上层
 
 应用：函数调用。每个进程都会有一个栈，每个frame中记录了调用函数的参数，自动变量和返回地址。当该函数调用一个新的函数时，栈中会push一个frame。当函数执行完毕返回时，该frame会pop，从而进入调用函数的原函数，继续执行。
 */
#include <stdio.h>

typedef struct stackNode *sPosition;
typedef int ElementTy;
typedef struct stackNode *stack;

struct stackNode  {
    ElementTy element;
    sPosition next;
};

stack init_stack(void);
void delete_stack(stack);
ElementTy top(stack);
void push(stack, ElementTy);
ElementTy pop(stack);
int is_empty(stack);

#endif /* stack_h */
