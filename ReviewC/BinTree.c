//
//  BinTree.c
//  ReviewC
//
//  Created by zhangdong on 2017/1/20.
//  Copyright © 2017年 __Nature__. All rights reserved.
//

/// 二叉树相关的知识
/// http://blog.csdn.net/fansongy/article/details/6798278  这篇文章写得不错

#include "BinTree.h"
typedef struct BinaryTreeNode BinaryTreeNode;
struct BinaryTreeNode {
    int value;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
};
