//
//  stack.cpp
//  stack_queue_and_recursion
//
//  Created by H Q on 2020/1/18.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "stack.hpp"
stack_arr::stack_arr(){
    a = new int[length];
}
stack_arr::~stack_arr(){
    delete []a;
}
bool stack_arr::push(int n){
    start++;
    if(start==length){
        return false;
    }else{
        a[start]=n;
        return true;
    }
}
int stack_arr::pop(){
    if(start==length)
        start--;
    if(start>=0){
        int p = a[start];
        start--;
        return p;
    }else{
        return -1;
    }
}

one_node::one_node(int c){
    content =c;
}
stack_linklist::stack_linklist(){
    head = new one_node(-10000000);
    start = head;
    pstart=nullptr;
}
stack_linklist::~stack_linklist(){
    if (head->next==nullptr) {
        delete head;
    }else{
        one_node *m;
        while(head->next!=nullptr){
            m=head->next;
            delete head;
            head = m;
        }
    }
}
int stack_linklist::push(int n){
    start->next=new one_node(n);
    pstart = start;
    start = start->next;
    return n;
}
int stack_linklist::pop(){
    one_node *p=head;
    int c;
    while(p!=pstart&& p->next!=pstart && p->next!=nullptr)
        p=p->next;
    if(p->next==pstart){
        c = start->content;
        delete start;
        start = pstart;
        start->next = nullptr;
        pstart = p;
    }else if(p==pstart && p->next!=nullptr){
        c = start->content;
        delete start;
        pstart->next=nullptr;
    }else{
        c=-1;
    }
    return c;
}
