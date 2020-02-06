//
//  queue.hpp
//  stack_queue_and_recursion
//
//  Created by H Q on 2020/1/18.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
class queue_arr{
public:
    int *a;
    int length=10;
    int start=0;
    int end = 0;
    queue_arr();
    ~queue_arr();
    bool enqueue(int n);
    int dequeue();
};

struct one_node_queue{
    int content;
    one_node_queue *next=nullptr;
    one_node_queue(int i);
};
class queue_linklist{
public:
    one_node_queue *head;
    one_node_queue *start;
    one_node_queue *end;
    
    queue_linklist();
    ~queue_linklist();
    bool enqueue(int n);
    int dequeue();
};
class circle_queue{
public:
    int *a;
    int length=10;
    int start=0;
    int end = 0;
    circle_queue();
    ~circle_queue();
    bool enqueue(int n);
    int dequeue();
};
#endif /* queue_hpp */
