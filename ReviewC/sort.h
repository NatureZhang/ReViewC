//
//  sort.h
//  ReviewC
//
//  Created by zhangdong on 16/7/4.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>

void bubleSort(int a[], int n);

void quickSort(int a[], int low, int high);
void quickSort2(int a[], int left, int right);

void selectSort(int a[], int n);

void insertionSort(int a[], int n);

void mergeSort(int a[], int first, int last, int temp[]);

void shellSort(int a[], int n);
#endif /* sort_h */
