//
//  heap.cpp
//  binary_tree_and_heap
//
//  Created by H Q on 2020/2/1.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "heap.hpp"
heap::heap(int l){
    count = 0;
    length = l;
    arr = new int[length+1];
}
heap::~heap(){
    delete []arr;
}

bigheap::bigheap(int l):heap(l){
}
void bigheap::insert(int content){
    count++;
    if(count>length){
        count--;
        return;
    }
    int index = count;
    //由下到上堆化
    while(index>=1){
        if(index/2>0 && arr[index/2]<content){
            arr[index]=arr[index/2];
            arr[index/2]=content;
            index=index/2;
        }else{
            arr[index]=content;
            break;
        }
    }
}
void bigheap::removeElement(){
    if(count==0)
        return;
    arr[1] = arr[count];
    arr[count]=-1;
    count--;
    int index = 1;
    //由上到下堆化
    while(2*index<=count){
        if(arr[index]<arr[2*index]||(arr[index]<arr[2*index+1]&&2*index+1<=count)){
            if(2*index+1<=count && arr[2*index]<=arr[2*index+1]){
                int temp = arr[index];
                arr[index] = arr[2*index+1];
                arr[2*index+1]=temp;
                index = 2*index+1;
            }else{
                int temp = arr[index];
                arr[index] = arr[2*index];
                arr[2*index]=temp;
                index = 2*index;
            }
        }else{
            break;
        }
    }
    
}
void bigheap::build(int *a, int n){
    for(int i=0;i<n;i++)
        arr[i+1]=a[i];
    count=n;
    for(int index=count/2;index>=1;index--){
        //由上到下堆化
        while(2*index<=count){
            if(arr[index]<arr[2*index]||(arr[index]<arr[2*index+1]&&2*index+1<=count)){
                if(2*index+1<=count && arr[2*index]<=arr[2*index+1]){
                    int temp = arr[index];
                    arr[index] = arr[2*index+1];
                    arr[2*index+1]=temp;
                    index = 2*index+1;
                }else{
                    int temp = arr[index];
                    arr[index] = arr[2*index];
                    arr[2*index]=temp;
                    index = 2*index;
                }
            }else{
                break;
            }
        }
    }
}
void singlesort(int *arr,int count){
    int temp=arr[1];
    arr[1] = arr[count];
    arr[count]=temp;
    count--;
    int index = 1;
    //由上到下堆化
    while(2*index<=count){
        if(arr[index]<arr[2*index]||(arr[index]<arr[2*index+1]&&2*index+1<=count)){
            if(2*index+1<=count && arr[2*index]<=arr[2*index+1]){
                int temp = arr[index];
                arr[index] = arr[2*index+1];
                arr[2*index+1]=temp;
                index = 2*index+1;
            }else{
                int temp = arr[index];
                arr[index] = arr[2*index];
                arr[2*index]=temp;
                index = 2*index;
            }
        }else{
            break;
        }
    }
}

void bigheap::sort(){
    for(int i=count; i>=1;i--)
        singlesort(arr,i);
    
}
smallheap::smallheap(int l):heap(l){
    
}
void smallheap::insert(int content){
    count++;
    if(count>length){
        count--;
        return;
    }
    int index = count;
    while(index>=1){
        if(index/2>0 && arr[index/2]>content){
            arr[index]=arr[index/2];
            arr[index/2]=content;
            index=index/2;
        }else{
            arr[index]=content;
            break;
        }
    }
}
void smallheap::removeElement(){
    if(count==0)
        return;
    arr[1] = arr[count];
    arr[count]=-1;
    count--;
    int index = 1;
    
    while(2*index<=count){
        if(arr[index]>arr[2*index]||(arr[index]>arr[2*index+1]&&2*index+1<=count)){
            if(2*index+1<=count && arr[2*index]>=arr[2*index+1]){
                int temp = arr[index];
                arr[index] = arr[2*index+1];
                arr[2*index+1]=temp;
                index = 2*index+1;
            }else{
                int temp = arr[index];
                arr[index] = arr[2*index];
                arr[2*index]=temp;
                index = 2*index;
            }
        }else{
            break;
        }
    }}

