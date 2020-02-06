//
//  sort.cpp
//  sort_and_binary
//
//  Created by H Q on 2020/1/30.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "sort.hpp"
void bubbleSort(int a[], int n){
    int count = 0;
    if(n<=1)
        return;
    for(int i=0;i<n;i++){//循环n次
        bool flag =false;
        for(int j=0;j<n-i-1;j++){//每次循环都进行相邻元素比较交换
            if(a[j]>a[j+1]){
                int temp =a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=true;
                count++;
            }
        }
        if(!flag)
            break;
    }
    cout<<count<<endl;
}
void insertSort(int a[], int n){
    if(n<=1)
        return;
    for(int i=0;i<n;i++){//分别对数组n个元素进行以下操作
        for(int j=0;j<i;j++){//每个元素插入到元素之前的有序数组中
            if(a[i]<a[j]){
                int temp = a[i];
                while(j<i){
                    a[i]=a[i-1];
                    i--;
                }
                a[j]=temp;
            }
        }
    }
}
void selectSort(int a[], int n){
    if(n<=1)
        return;
    for(int i=0;i<n;i++){
        int minj=-1;
        int min=1000;
        for(int j=i;j<n;j++){
            if(a[j]<min){
                min=a[j];
                minj=j;
            }
        }
        a[minj]=a[i];
        a[i]=min;
    }
}

void merge(int a[], int p, int m, int q){//p->m,m+1->q
    int *temp = new int[q-p+1];
    int i=p,j=m+1,k=0;
    while(true){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
        }else{
            temp[k]=a[j];
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
    //delete []temp;
}
void mergeSort(int a[], int p,int q){
    if(p>=q)
        return;
    int m=(p+q)/2;
    mergeSort(a, p, m);
    mergeSort(a, m+1, q);
    merge(a,p,m,q);
}

int partion(int a[], int p, int q){
    int refer =a[q];
    int i=p;//0-i都是有规律的，小于refer的
    for(int j=p;j<=q;j++){
        if(a[j]<refer){
            int temp = a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    a[q]=a[i];
    a[i]=refer;
    return i;
}
void quickSort(int a[], int p, int q){
    if(p>=q)
        return;
    int m= partion(a, p, q);//排好，p,m,m+1,q
    quickSort(a, p, m-1);
    quickSort(a, m+1, q);
}

void quickSearch(int a[], int p, int q, int K){
    if(p>q)
        return;
    int m= partion(a, p, q);//排好，p,m,m+1,q
    if(m+1<K)
        quickSearch(a, m+1, q,K);
    else if(m+1>K)
        quickSearch(a, p, m-1,K);
    else{
        cout<<a[m]<<endl;
        return;
    }
}
