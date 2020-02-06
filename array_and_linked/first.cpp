//
//  first.cpp
//  array_and_linked
//
//  Created by H Q on 2020/1/16.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "first.hpp"
#include "iostream"
using namespace std;

arr_dynamic::arr_dynamic(){
    a= new int[10];
    length=10;
    count=0;
}
arr_dynamic::~arr_dynamic(){
    delete []a;
}
void arr_dynamic::add(int n){
    count++;
    if(count>length){
        int *temp = new int[length*2];
        for(int i=0;i<length;i++){
            temp[i]=a[i];
        }
        temp[count-1]=n;
        delete []a;
        length*=2;
        a = temp;
    }else{
        a[count-1]= n;
    }
}
void arr_dynamic::del(int index){
    count--;
    for(int i = index;i<length-1;i++){
        a[i]=a[i+1];
    }
    if(length/count==2){
        int *temp = new int[count];
        for(int i=0;i<count;i++){
            temp[i]=a[i];
        }
        delete []a;
        length/=2;
        a = temp;
    }
}

arr_order::arr_order(){
    a= new int[10];
    length=10;
    count=0;
}
arr_order::~arr_order(){
    delete []a;
}
bool arr_order::add(int n){
    if(count==length)
        return false;
    int ind= search(n);
    if(ind!=count){
        for(int i=count;i>ind;i--){
            a[i]=a[i-1];
        }
    }
    a[ind]=n;
    count++;
    return true;
}
bool arr_order::del(int n){
    if(count==0)
        return false;
    int ind = search(n);
    if(a[ind]!=n||ind==count)
        return false;
    for(int i=ind;i<count-1;i++){
        a[i]=a[i+1];
    }
    count--;
    return true;
}
int arr_order::search(int n){
    //o-count-1
    for(int i=0;i<count;i++){
        if(a[i]>=n||a[0]>n)
            return i;
    }
    return count;
};
    
