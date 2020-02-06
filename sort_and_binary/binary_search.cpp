//
//  binary_search.cpp
//  sort_and_binary
//
//  Created by H Q on 2020/1/30.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "binary_search.hpp"
int binarySearch(int a[], int n, int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(a[mid]<target)
            left = mid+1;
        else if(a[mid]>target)
            right = mid-1;
        else
            return mid;
    }
    return -1;
}

int obscureBinarySearch(int a[], int n, int target){//第一个大于等于target的元素。
    int left=0,right=n-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(a[mid]>=target){
            if(mid==0 || a[mid-1]<target)//mid元素必须满足的条件
                return mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return -1;
}
