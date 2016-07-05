//
//  sort.c
//  ReviewC
//
//  Created by zhangdong on 16/7/4.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

// 假设计算机每秒钟运行 10亿 次

/**
 *  排序算法
 */

#include "sort.h"

// 冒泡排序
void bubleSort(int a[], int n) {
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// 快速排序 东尼霍尔 1960
// 1 先从数列中取出一个数作为基准书
// 2 分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放在它的左边
// 3 再对左右区间重复第二步，直到各区间只有一个数
// 时间复杂度：最坏O(N2), 它的平均时间复杂度O（NlogN）
void quickSort(int a[], int low, int high) {

    int key = a[low];
    int i = low;
    int j = high;
    
    if (low > high) {
        return;
    }
    
    while (i < j) {
        while ((i < j) && (key <= a[j])) { // 从右向左找第一个小于key的数
            j--;
        }
        
        if (i < j) {
            a[i++] = a[j];
        }
        
        while (i < j && a[i] < key) {
            i ++;
        }
        
        if (i < j) {
            a[j--] = a[i];
        }
    }
    
    a[i] = key;
    quickSort(a, low, i - 1);
    quickSort(a, i + 1, high);
}


// 这个是比较好理解的
void quickSort2(int a[], int left, int right) {
    
    int i , j, t, temp;
    if (left > right) {
        return;
    }
    
    temp = a[left]; // temp 中存的数，就是基准数
    i = left;
    j = right;
    
    while (i !=  j) {
        
        // 顺序很重要，要先从右边开始找
        while (a[j] >= temp && i < j) {
            j --;
        }
        
        // 再找左边的
        while (a[i] <= temp && i < j) {
            i ++;
        }
        
        // 交换两个数在数组中的位置
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        
    }
    
    // 最终将基准数 归位
    a[left] = a[i];
    a[i] = temp;
    
    quickSort2(a, left, i - 1); // 继续处理左边的，递归
    quickSort2(a, i + 1, right);// 继续处理右边的，递归
}

/**
 *  选择排序
 
    首先在未排序序列中找到最小元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中
    继续寻找最小元素，然后放到排序序列（已经排好序）末位
 
 */
void selectSort(int a[], int n) {
    
    for (int i = 0; i < n - 1; i++) { //n个数进行n-1趟排序，每次确定一个最小的放在a[i]中
        
        int k = i;  // k 指向最小的数
        for (int j = i + 1; j < n; j++) {
            if (a[k] > a[j]) {
                k = j;          //k 指向最小的数
            }
        }
        
        if (k != i) {
            
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
}

/**
 *  归并排序
 */


/**
 *  希尔排序
 */

/**
 *  堆排序
 */

/**
 *  直接插入排序
 */

/**
 *  带哨兵的直接插入排序呢
 */

















