//
//  sort.hpp
//  sort_and_binary
//
//  Created by H Q on 2020/1/30.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include <stdio.h>
#include "iostream"
using namespace std;
void bubbleSort(int a[], int n);
void insertSort(int a[], int n);
void selectSort(int a[], int n);
void mergeSort(int a[], int p, int q);
void quickSort(int a[], int p, int q);
void quickSearch(int a[], int p, int q, int K);
#endif /* sort_hpp */
