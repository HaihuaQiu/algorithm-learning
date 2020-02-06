//
//  second.hpp
//  array_and_linked
//
//  Created by H Q on 2020/1/17.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef second_hpp
#define second_hpp

#include <stdio.h>
struct one_point{
    int content;
    one_point *next=nullptr;
    one_point(int c);
};
struct two_point{
    int content;
    two_point *left=nullptr;
    two_point *right=nullptr;
    two_point(int c);
};
class sll{
public:
    one_point *head;
    sll();
    ~sll();
    void add(one_point *p);
    void del(int content);
};
class dll{
public:
    two_point *head;
    dll();
    ~dll();
    void add(two_point *p);
    void del(int content);
};
class cll{
public:
    one_point *head;
    cll();
    ~cll();
    void add(one_point *p);
    void del(int content);
};



#endif /* second_hpp */
