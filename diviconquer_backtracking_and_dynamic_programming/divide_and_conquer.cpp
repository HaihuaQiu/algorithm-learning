//
//  divide_and_conquer.cpp
//  diviconquer_backtracking_and_dynamic_programming
//
//  Created by H Q on 2020/2/4.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "divide_and_conquer.hpp"
int merge(int a[], int p, int m, int q){//p->m,m+1->q
    int *temp = new int[q-p+1];
    int i=p,j=m+1,k=0;
    int count=0;
    while(true){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
        }else{
            temp[k]=a[j];
            count+= m-i+1;
            j++;
        }
        k++;
        if(i>m){
            while(j<=q){
                temp[k]=a[j];
                k++;
                j++;
            }
            break;
        }
        if(j>q){
            while(i<=m){
                temp[k]=a[i];
                k++;
                i++;
            }
            break;
        }
    }
    for(int z=p;z<=q;z++)
        a[z]=temp[z-p];
    return count;
    //delete []temp;
}
int mergeSort(int a[], int p,int q){
    if(p>=q)
        return 0;
    int m=(p+q)/2;
    int temp = mergeSort(a, p, m)+mergeSort(a, m+1, q);
    return temp+merge(a,p,m,q);
}
