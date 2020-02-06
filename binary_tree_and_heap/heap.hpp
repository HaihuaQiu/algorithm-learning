//
//  heap.hpp
//  binary_tree_and_heap
//
//  Created by H Q on 2020/2/1.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>
class heap{
public:
    int length;
    int count;
    int *arr;
    heap(int l);
    ~heap();
    virtual void insert(int content)=0;
    virtual void removeElement()=0;
    
};

class bigheap:public heap{
public:
    bigheap(int l);
    virtual void insert(int content);
    virtual void removeElement();
    void build(int *a, int n);
    void sort();
};

class smallheap:public heap{
public:
    smallheap(int l);
    virtual void insert(int content);
    virtual void removeElement();
};


#endif /* heap_hpp */
