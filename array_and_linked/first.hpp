//
//  first.hpp
//  array_and_linked
//
//  Created by H Q on 2020/1/16.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef first_hpp
#define first_hpp

#include <stdio.h>

class arr_dynamic{
public:
    int *a;
    int length;
    int count;
    arr_dynamic();
    ~arr_dynamic();
    void add(int n);
    void del(int index);
};

class arr_order{
public:
    int *a;
    int length;
    int count;
    arr_order();
    ~arr_order();
    bool add(int n);
    bool del(int n);
    int search(int n);
};
#endif /* first_hpp */
