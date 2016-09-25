//
//  search.c
//  ReviewC
//
//  Created by zhangdong on 16/7/4.
//  Copyright © 2016年 __Nature__. All rights reserved.
//

/**
 *  查找算法
 */

#include "search.h"

int binarySearch(int a[], int n, int key) {
    
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        
        int mid = (low + high) / 2;
        int midVal = a[mid];
        if (midVal < key) {
            low = mid + 1;
        }
        else if (midVal > key){
            high = mid - 1;
        }
        else {
            return mid;
        }
        
    }
    
    return -1;
}