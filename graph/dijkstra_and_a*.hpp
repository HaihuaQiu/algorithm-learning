//
//  dijkstra_and_a*.hpp
//  graph
//
//  Created by H Q on 2020/2/2.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef dijkstra_and_a__hpp
#define dijkstra_and_a__hpp

#include <stdio.h>
#include "graph_representation.hpp"
class vertex{//要放入小顶堆的顶点
public:
    int id;
    long dist;
    vertex();
    vertex(int id,int dist);
};

class priority_queue{
public:
    int length;
    int count;
    vertex *arr;
    priority_queue(int l);
    ~priority_queue();
    void insert(vertex* v);
    void update(vertex* v);
    void removeElement();
    bool empty();
};
void dijkstra( int start, int target, adjacencylist m);

//astar
class vertex_astar:public vertex{
public:
    int x,y;
    long f;
    vertex_astar();
    vertex_astar(int id, int dist, int x, int y);
};
class priority_queue_astar{
public:
    int length;
    int count;
    vertex_astar *arr;
    priority_queue_astar(int l);
    ~priority_queue_astar();
    void insert(vertex_astar* v);
    void update(vertex_astar* v);
    void removeElement();
    bool empty();
};
void astar( int start, int target, adjacencylist m, int *x, int *y);

#endif /* dijkstra_and_a__hpp */
