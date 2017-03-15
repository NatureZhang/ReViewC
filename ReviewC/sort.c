//
//  sort.c
//  ReviewC
//
//  Created by zhangdong on 16/7/4.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

// 假设计算机每秒钟运行 10亿 次

/**
 *  排序算法 http://www.cnblogs.com/kkun/archive/2011/11/23/2260312.html
 *  算法复杂度 http://www.cnblogs.com/nannanITeye/archive/2013/04/11/3013737.html
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

int partition(int a[], int left, int right){
    
    if (a == NULL || left < 0 || left > right) {
        return -1;
    }
    
    int i, j, t, tmp;
    tmp = a[left];
    i = left;
    j = right;
    
    while (i != j) {
        
        //从右往前找
        while (a[j] >= tmp && i < j) {
            j --;
        }
        
        while (a[i] <= tmp && i < j) {
            i ++;
        }
        
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        
    }
    
    // 最终将基准数 归位
    a[left] = a[i];
    a[i] = tmp;

    return i;
}

// 这个是比较好理解的
void quickSort2(int a[], int left, int right) {
    
//    int i , j, t, temp;
//    if (left > right) {
//        return;
//    }
//    
//    temp = a[left]; // temp 中存的数，就是基准数
//    i = left;
//    j = right;
//    
//    while (i !=  j) {
//        
//        // 顺序很重要，要先从右边开始找
//        while (a[j] >= temp && i < j) {
//            j --;
//        }
//        
//        // 再找左边的
//        while (a[i] <= temp && i < j) {
//            i ++;
//        }
//        
//        // 交换两个数在数组中的位置
//        if (i < j) {
//            t = a[i];
//            a[i] = a[j];
//            a[j] = t;
//        }
//        
//    }
//    
//    // 最终将基准数 归位
//    a[left] = a[i];
//    a[i] = temp;
    
    int i = partition(a, left, right);
    
    if (i > left)
    quickSort2(a, left, i - 1); // 继续处理左边的，递归
    
    if (i < right)
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
    把原始数组分成若干子数组，对每一个子数组进行排序，继续把子数组与子数组合并，合并后仍然有序，直到全部合并完，形成有序的数组
 
    设数列长为N， 将数列分开成小数列一共要logN步，每步都是一个合并有序数列的过程，时间复杂度记为O(N),故一共O(N*logN)
 */

void mergeArray(int a[], int first, int mid, int last, int temp[]) {
    
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;
    
    while (i <= m && j <= n) {
        
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }
    
    while (i <= m) {
        temp[k++] = a[i++];
    }
    
    for (i = 0; i < k; i ++) {
        a[first + i] = temp[i];
    }
}

void mergeSort(int a[], int first, int last, int temp[]) {
    
    if (first < last) {
        
        int mid = (first + last) / 2;
        mergeSort(a, first, mid, temp);         // 左边有序
        mergeSort(a, mid + 1, last, temp);      // 右边有序
        mergeArray(a, first, mid, last, temp);  // 再将两个有序数组合并
    }
}

/**
 *  希尔排序
 */

void shellSort(int a[], int n) {
    int group, i, j, temp;
    for (group = n / 2; group > 0; group /= 2) {
        for (i = group; i < n; i++) {
            
            for (j = i - group; j >= 0; j-= group) {
                if (a[j] > a[j + group]) {
                    temp = a[j];
                    a[j] = a[j + group];
                    a[j + group] = temp;
                }
            }
        }
    }
}

/**
 *  堆排序
 */

/**
 *  直接插入排序
 插入排序就是每一步都将一个待排序数据按其大小，插入到已经排序的数据中的适当位置，直到全部插入完毕
 时间复杂度 O(n2) 最好O(n)
 */

void insertionSort(int a[], int n) {
    
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            
            int temp = a[i];
            int j = i;
            while (j > 0 && a[j - 1] > temp) {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = temp;
        }
    }
    
}


















