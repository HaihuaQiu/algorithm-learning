//
//  second.cpp
//  array_and_linked
//
//  Created by H Q on 2020/1/17.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "second.hpp"
one_point::one_point(int c){
    content=c;
}
sll::sll(){
    head = new one_point(-1000000);
    head->next=nullptr;
}
sll::~sll(){
    if (head->next==nullptr) {
        delete head;
    }else{
        one_point *m;
        while(head->next!=nullptr){
            m=head->next;
            delete head;
            head = m;
        }
    }
}
void sll::add(one_point *p){
    one_point *start= head;
    one_point *pstart= head;
    while(start->next!=nullptr && start->content<p->content){
        pstart=start;
        start=start->next;
    }
    if(start->next!=nullptr || start->content>p->content){
        p->next=start;
        pstart->next=p;
    }else{
        start->next=p;
    }
}
void sll::del(int content){
    one_point *start= head;
    one_point *pstart= head;
    while(start->next!=nullptr && start->content!=content){
        pstart=start;
        start=start->next;
    }
    if(start->content==content){
        pstart->next=start->next;
        delete start;
    }
}

two_point::two_point(int c){
    content=c;
}
dll::dll(){
    head = new two_point(-1000000);
}
dll::~dll(){
    if (head->right==nullptr) {
        delete head;
    }else{
        two_point *m;
        while(head->right!=nullptr){
            m=head->right;
            delete head;
            head = m;
        }
    }
}
void dll::add(two_point *p){
    two_point *start= head;
    two_point *pstart= head;
    while(start->right!=nullptr && start->content<p->content){
        pstart=start;
        start=start->right;
    }
    if(start->right!=nullptr || start->content>p->content){
        p->right=start;
        pstart->right=p;
        p->left=pstart;
        start->left=p;
    }else{
        start->right=p;
        p->left=start;
    }
}


void dll::del(int content){
    two_point *start= head;
    two_point *pstart= head;
    while(start->right!=nullptr && start->content!=content){
        pstart=start;
        start=start->right;
    }
    if(start->content==content){
        if(start->right!=nullptr){
            pstart->right=start->right;
            pstart->right->left=pstart;
        }
        else
            pstart->right=nullptr;
        delete start;
    }
}


cll::cll(){
    head = new one_point(-1000000);
    head->next=nullptr;
}
cll::~cll(){
    if (head->next==nullptr) {
        delete head;
    }else{
        one_point *m;
        one_point *h=head->next;
        while(h->next!=nullptr){
            m=h->next;
            delete h;
            if(m->next==head->next)
                break;
            h = m;
        }
        delete head;
    }
}
void cll::add(one_point *p){
    p->next=p;
    one_point *start= head;
    one_point *pstart= head;
    if(start->next==nullptr)
        start->next=p;
    else{
        start=start->next;
        while(start->next!=head->next && start->content<p->content){
            pstart=start;
            start=start->next;
            
        }
        //>1 node
        if(start->next!=head->next){
            p->next=start;
            pstart->next=p;
        }else{
            p->next=head->next;
            start->next = p;
        }
    }
}
void cll::del(int content){
    one_point *start= head->next->next;
    one_point *pstart= head->next;
    while(start->next!=head->next->next && start->content!=content){//very important: judge circle condition
        pstart=start;
        start=start->next;
    }
    if(start->content==content){
        if(start->next==start){
            head->next=nullptr;
        }else{
            if(start==head->next)
                head->next=start->next;
            pstart->next=start->next;
            
        }
        delete start;
    }
}
