//
//  main.cpp
//  diviconquer_backtracking_and_dynamic_programming
//
//  Created by H Q on 2020/2/4.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include <iostream>
#include "divide_and_conquer.hpp"
#include "backtracking.hpp"
#include "dynamic_programming.hpp"
using namespace std;
void test_divide_and_conquer_reversed_order();
void test_eight_queen();
void test_zero_one_package_simple();
void test_zero_one_package_dp();
void test_min_path_sum();
void test_edit_distance();
void test_mostIncreseSubstring();
int main(int argc, const char * argv[]) {
    // insert code here...
    //test_divide_and_conquer_reversed_order();
    //test_eight_queen();
    //test_zero_one_package_simple();
    //test_zero_one_package_dp();
    //test_min_path_sum();
    //test_edit_distance();
    //test_mostIncreseSubstring();
    return 0;
}
void test_divide_and_conquer_reversed_order(){
    int a[]={2,4,3,1,5,6};
    int n=6;
    cout<<mergeSort(a, 0, n-1)<<endl;
    int a1[]={1,2,3,4,5,6};
    int n1=6;
    cout<<mergeSort(a1, 0, n1-1)<<endl;
    int a2[]={6,5,4,3,2,1};
    int n2=6;
    cout<<mergeSort(a2, 0, n2-1)<<endl;
}
void test_eight_queen(){
    eight_queen();
}
void test_zero_one_package_simple(){
    const int n=5;
    int weight[n]={2,2,4,6,3};
    int limited =9;
    zero_one_package(weight, n, limited);
}
void test_zero_one_package_dp(){
    const int n=5;
    int weight[n]={2,2,4,6,3};
    int limited =9;
    zero_one_package_dp(weight, n, limited);
}
void test_min_path_sum(){
    const int n= 4;
    int grid[n][n]={1,3,5,9,2,1,3,4,5,2,6,7,6,8,4,3};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<minPathSum(grid, n)<<endl;
}
void test_edit_distance(){
    char a[]="mitcmu";
    char b[]="mtacnu";
    int m=6,n=6;
    cout<<shortestLevensteinEditDistance(a, m, b, n)<<endl;
    cout<<longestCommonStringDistance(a, m, b, n)<<endl;
}
void test_mostIncreseSubstring(){
    int a[9]={2,1,5,3,6,4,8,9,7};
    mostIncreseSubstring(a, 9);
}
