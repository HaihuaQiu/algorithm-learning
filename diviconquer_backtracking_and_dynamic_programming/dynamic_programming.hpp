//
//  dynamic_programming.hpp
//  diviconquer_backtracking_and_dynamic_programming
//
//  Created by H Q on 2020/2/4.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef dynamic_programming_hpp
#define dynamic_programming_hpp

#include <stdio.h>
void zero_one_package_dp(int* weight, int n, int maxWeight);
int minPathSum(int grid[][4],int n);
int shortestLevensteinEditDistance(char a[], int m, char b[], int n);
int longestCommonStringDistance(char a[], int m, char b[], int n);
void mostIncreseSubstring(int a[], int n);
#endif /* dynamic_programming_hpp */
