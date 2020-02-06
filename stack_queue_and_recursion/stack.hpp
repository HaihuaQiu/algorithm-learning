//
//  stack.hpp
//  stack_queue_and_recursion
//
//  Created by H Q on 2020/1/18.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
class stack_arr{
public:
    int *a;
    int length=10;
    int start=-1;
    stack_arr();
    ~stack_arr();
    bool push(int n);
    int pop();
};

struct one_node{
    int content;
    one_node *next=nullptr;
    one_node(int i);
};
class stack_linklist{
public:
    one_node *head;
    one_node *start;
    one_node *pstart;
    
    stack_linklist();
    ~stack_linklist();
    int push(int n);
    int pop();
};
#endif /* stack_hpp */
