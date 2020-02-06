//
//  hash_table.cpp
//  hash_table_and_string
//
//  Created by H Q on 2020/1/31.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "hash_table.hpp"
one_point::one_point(){
    content=-10000;
}
one_point::one_point(int c){
    content=c;
}

hash_table::hash_table(){
    a = new one_point[length]();
}
hash_table::~hash_table(){
    delete []a;
}
int hash_table::hash_function(int key){
    return key%length;
}
bool hash_table::add(int content){
    int index = hash_function(content);
    one_point* one = new one_point(content);
    one->next=a[index].next;
    a[index].next=one;
    return true;
}
bool hash_table::del(int content){
    int index = hash_function(content);
    one_point* p = &a[index];
    one_point* pp=nullptr;
    while(p!=nullptr){
        if(p->content==content){
            pp->next=p->next;
            delete p;
            return true;
        }
        pp=p;
        p=p->next;
    }
    return false;
}
int hash_table::search(int content){
    int index = hash_function(content);
    one_point* p = a[index].next;
    while(p!=nullptr){
        if(p->content==content){
            return index;
        }
        p=p->next;
    }
    return -1;
}



three_point::three_point(int c){
    content = c;
}
three_point::three_point(){
    content = -10000;
}
lru::lru(){
    head= new three_point();
    tail=head;
    hash_table = new three_point[length]();
    
}
    
lru::~lru(){
    while(head!=nullptr){
        tail = head;
        head=head->next;
        delete tail;
    }
    delete []hash_table;
}
    
int lru::hash_function(int key){
    return key%length;
}
    
bool lru::add(int content){
    if(search(content)!=-1){
        return true;
    }else{
        count++;
        if(count>limit){
            //del linklist表头节点
            //删除linklist节点
            three_point *p = head->right;
            three_point *pp= p->left;
            pp->right=p->right;
            if(pp->right!=nullptr)
                pp->right->left = pp;
            
            //删除hashtable节点
            three_point *search = hash_table[hash_function(p->content)].next;
            three_point *pr =nullptr;
            while(p!=search){
                pr = search;
                search = search->next;
            }
            pr->next = p->next;
            delete p;
            count--;
        }
        //加入hashtable
        int index = hash_function(content);
        three_point* one = new three_point(content);
        one->next=hash_table[index].next;
        hash_table[index].next=one;
        //加入linklist
        tail->right = one;
        one->left=tail;
        tail = one;
        return true;
    }
}
    
bool lru::del(int content){
    int index = hash_function(content);
    three_point* p = &hash_table[index];
    three_point* pr = nullptr;
    while(p!=nullptr){
        if(p->content==content){
            //删除链表元素
            three_point *pp= p->left;
            pp->right=p->right;
            if(pp->right!=nullptr)
                pp->right->left = pp;
            
            //删除hashtable元素
            pr->next=p->next;
            delete p;
            count--;
            return true;
        }
        pr=p;
        p=p->next;
    }
    return false;
}
    
int lru::search(int content){
    int index = hash_function(content);
    three_point* p = hash_table[index].next;
    while(p!=nullptr){
        if(p->content==content){
            //只修改链表元素
            if(p->right!=nullptr){
                three_point *pp= p->left;
                pp->right=p->right;
                tail->right = p;
                p->left=tail;
                p->right = nullptr;
                tail = p; 
            }
            return index;
        }
        p=p->next;
    }
    return -1;
}
    
