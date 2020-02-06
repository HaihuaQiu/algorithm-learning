//
//  backtracking.cpp
//  diviconquer_backtracking_and_dynamic_programming
//
//  Created by H Q on 2020/2/4.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "backtracking.hpp"
#include "iostream"
using namespace std;

//eight_queen
bool judge(int row,int *result,int column){
    int index = 0;
    if(row==0)
        return true;
    for(int i=row-1;i>=0;i--){
        if(result[i]==column)
            return false;
        index++;
        if(column-index>=0 && result[i]==column-index){
            return false;
        }
        if(column+index<=7 && result[i]==column+index){
            return false;
        }
    }
    return true;
}
void print(int *pre){
    for (int row = 0; row < 8; ++row){
        for (int column = 0; column < 8; ++column) {
            if (pre[row] == column)
                cout<<"Q ";
            else
                cout<<"* ";
            
        }
        cout<<endl;;
    }
    cout<<endl;
}

void call_eight_queen(int row, int* result){
    if(row>7){
        print(result);
        return;
    }
    for(int column=0;column<8;column++){
        if(judge(row,result,column)){
            result[row]=column;
            call_eight_queen(row+1,result);
            //result[row]=-1;
        }
    }
}
void eight_queen(){
    int* result = new int[8];
    for(int i=0 ;i<0;i++){
        result[i]=-1;
    }
    call_eight_queen(0,result);
}

//zero_one_package
void search(int* weight, int index, int ac_weight,int& maxWeight,int limited,int n){
    if (ac_weight>limited||index>=n) {
        return;
    }
    if(ac_weight>maxWeight){
        maxWeight=ac_weight;
    }
    search(weight, index+1, ac_weight,maxWeight,limited,n);
    search(weight, index+1, ac_weight+weight[index+1],maxWeight,limited,n);
}
void zero_one_package(int* weight, int n, int limited){
    int maxWeight=-100;
    search(weight,-1,0,maxWeight,limited,n);
    cout<<maxWeight<<endl;
}
