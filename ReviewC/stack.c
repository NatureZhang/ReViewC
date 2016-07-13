//
//  stack.c
//  ReviewC
//
//  Created by zhangdong on 16/7/13.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>

stack init_stack(void) {
    
    sPosition np;
    stack sk;
    np = (sPosition)malloc(sizeof(struct stackNode));
    np -> next = NULL;
    sk = np;
    return sk;
}

void delete_stack(stack sk) {
    while (!is_empty(sk)) {
        pop(sk);
    }
    
    free(sk);
}

ElementTy top(stack sk) {
    return sk->next->element;
}

void push(stack sk, ElementTy value) {
    
    sPosition np, oldTop;
    oldTop = sk->next;
    
    np = (sPosition) malloc(sizeof(struct stackNode));
    np->element = value;
    np->next = sk->next;
    sk->next = np;
}

ElementTy pop(stack sk) {
    ElementTy element;
    sPosition top, newTop;
    if (is_empty(sk)) {
        printf("pop() on an empty stack");
        exit(1);
    }
    else{
        top = sk->next;
        element = top->element;
        newTop = top->next;
        sk->next = newTop;
        free(top);
        return element;
    }
}

int is_empty(stack sk) {
    return (sk->next == NULL);
}

