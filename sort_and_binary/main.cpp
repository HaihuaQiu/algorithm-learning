//
//  main.cpp
//  sort_and_binary
//
//  Created by H Q on 2020/1/30.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include <iostream>
#include "sort.hpp"
#include "binary_search.hpp"
using namespace std;
void test_bubblesort();
void test_insertsort();
void test_selectsort();
void test_mergesort();
void test_quicksort();
void test_quicksearch();
void test_binarysearch();
void test_obscurebinarysearch();
int main(int argc, const char * argv[]) {
    // insert code here...
    //test_bubblesort();
    //test_insertsort();
    //test_selectsort();
    //test_mergesort();
    //test_quicksort();
    //test_quicksearch();
    //test_binarysearch();
    test_obscurebinarysearch();
    return 0;
}
void test_bubblesort(){
    int a[]={4,6,3,7,5,2};
    int n=6;
    bubbleSort(a, n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void test_insertsort(){
    int a[]={4,6,3,7,5,2};
    int n=6;
    insertSort(a, n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void test_selectsort(){
    int a[]={4,6,3,7,5,2};
    int n=6;
    selectSort(a, n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void test_mergesort(){
    int a[]={4,6,3,7,5,2};
    int n=6;
    mergeSort(a, 0, n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void test_quicksort(){
    int a[]={4,6,3,7,5,2};
    int n=6;
    quickSort(a, 0, n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void test_quicksearch(){
    int n=6;
    for(int i=0;i<n;i++){
        int a[]={4,6,3,7,5,2};
        quickSearch(a, 0, n-1, i);
        
    }
}
void test_binarysearch(){
    int a[]={2,3,4,5,6,7};
    int n=6;
    for(int i=2;i<8;i++)
        cout<<binarySearch(a, n, i)<<endl;
}
void test_obscurebinarysearch(){
    int a[]={2,4,6,7,7};
    int n=5;
    cout<<obscureBinarySearch(a, n, 3)<<endl;
    cout<<obscureBinarySearch(a, n, 5)<<endl;
    cout<<obscureBinarySearch(a, n, 7)<<endl;
}
