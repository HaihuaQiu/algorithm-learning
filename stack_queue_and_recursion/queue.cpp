//
//  queue.cpp
//  stack_queue_and_recursion
//
//  Created by H Q on 2020/1/18.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "queue.hpp"
queue_arr::queue_arr(){
    a = new int[length];
}
queue_arr::~queue_arr(){
    delete []a;
}
bool queue_arr::enqueue(int n){
    if(end<length){
        a[end]=n;
        end++;
        return true;
    }else{
        if(start==0)
            return false;
        else{
            for(int i=0;i+start<length;i++){
                a[i]=a[i+start];
            }
            end-=start;
            a[end]=n;
            end++;
            start=0;
            return true;
        }
    }
}
int queue_arr::dequeue(){
    if(start==end)
        return -1;
    int temp =a[start];
    start++;
    return temp;
}

one_node_queue::one_node_queue(int c){
    content = c;
}

queue_linklist::queue_linklist(){
    start = nullptr;
    end = nullptr;
}
queue_linklist::~queue_linklist(){
    while(start!=nullptr){
        one_node_queue *p = start->next;
        delete start;
        start = p;
    }
}
bool queue_linklist::enqueue(int n){
    one_node_queue *p = new one_node_queue(n);
    if(start==nullptr && end==nullptr){
        start=p;
        end=p;
        return true;
    }
    end->next= p;
    end=end->next;
    return true;
}
int queue_linklist::dequeue(){
    if(end==nullptr)
        return -1;
    one_node_queue *p = start->next;
    if(p==nullptr){
        end =p;
    }
    int temp = start->content;
    delete start;
    start = p;
    return temp;
}

circle_queue::circle_queue(){
    a = new int[length];
}
circle_queue::~circle_queue(){
    delete []a;
}
bool circle_queue::enqueue(int n){//end指向未定值，start指向有值。
    if((end+1)%length==start)
        return false;
    else{
        a[end]=n;
        end = (end+1)%length;
        return true;
    }
}
int circle_queue::dequeue(){
    if(start==end)
        return -1;
    else{
        int temp = a[start];
        start = (start+1)%length;
        return temp;
    }
}
