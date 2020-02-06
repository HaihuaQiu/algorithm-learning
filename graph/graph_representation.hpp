//
//  graph_representation.hpp
//  graph
//
//  Created by H Q on 2020/2/2.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef graph_representation_hpp
#define graph_representation_hpp

#include <stdio.h>
class adjacencymatrix{
public:
    int elementnum;
    bool direction;
    int **graph;
    adjacencymatrix(int num, bool dir);
    void insert(int i, int j, int weight=1);
    ~adjacencymatrix();
};

struct one_point{
    int weight;
    int content;
    one_point *next=nullptr;
    one_point();
    one_point(int i, int c);
};

class adjacencylist{
public:
    int elementnum;
    bool direction;
    one_point *graph;
    adjacencylist(int num, bool dir);
    void insert(int i, int j, int weight=1);
};

#endif /* graph_representation_hpp */
