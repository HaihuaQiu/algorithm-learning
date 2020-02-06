//
//  hash_table.hpp
//  hash_table_and_string
//
//  Created by H Q on 2020/1/31.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef hash_table_hpp
#define hash_table_hpp

#include <stdio.h>
struct one_point{
    int content;
    one_point *next=nullptr;
    one_point();
    one_point(int c);
};

class hash_table{
public:
    int length=10;
    one_point* a;
    hash_table();
    ~hash_table();
    int hash_function(int key);
    bool add(int content);
    bool del(int content);
    int search(int content);
};

struct three_point{
    int content;
    three_point *left=nullptr;
    three_point *right=nullptr;
    three_point *next=nullptr;
    three_point(int c);
    three_point();
};

class lru{
public:
    int length=10;
    int limit=15;
    int count=0;
    three_point* head;//lru链表，越前面访问的放在越前面。
    three_point* tail;
    three_point* hash_table;
    lru();
    ~lru();
    int hash_function(int key);
    bool add(int content);
    bool del(int content);
    int search(int content);};
#endif /* hash_table_hpp */
