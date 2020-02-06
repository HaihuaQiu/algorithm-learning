//
//  recurision.cpp
//  stack_queue_and_recursion
//
//  Created by H Q on 2020/1/18.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "recurision.hpp"
#include <iostream>
int fibonaci(int n){
    if(n == 0  || n ==1)
        return 1;
    return fibonaci(n-1)+fibonaci(n-2);
}
int fj(int n){
    if(n==0 || n==1)
        return 1;
    return n*fj(n-1);
}
void arrange(std::string s, std::string refer, int index, bool used[]){
    if(index ==0)
        s=refer.c_str();
    if(index==s.length()){
        std::cout<<s<<std::endl;
        return;
    }
    
    for(int pos=0; pos<s.length();pos++){//第index个元素，第pos位置
        if(!used[pos]){
            //int temp = s[pos];
            s[pos]= refer[index];
            used[pos]=true;
            arrange(s,refer, index+1, used);
            //s[pos]=temp;
            used[pos]=false;
        }
    }
}
