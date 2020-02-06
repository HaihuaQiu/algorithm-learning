//
//  graph_representation.cpp
//  graph
//
//  Created by H Q on 2020/2/2.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "graph_representation.hpp"
adjacencymatrix::adjacencymatrix(int num, bool dir){
    elementnum = num;
    direction = dir;
    graph = new int *[elementnum];
    for(int i=0;i<elementnum;i++)
        graph[i]= new int[elementnum];
    for(int i=0;i<elementnum;i++)
        for(int j=0;j<elementnum;j++)
            graph[i][j]=0;
}
void adjacencymatrix::insert(int i, int j, int weight){
    graph[i-1][j-1]=weight;
    if(!direction)
        graph[j-1][i-1]=weight;
}
adjacencymatrix::~adjacencymatrix(){
    for(int i=0;i<elementnum;i++)
        delete [] graph[i];
    delete [] graph;
}

one_point::one_point(){
    weight=-10000;
}
one_point::one_point(int i, int c){
    content = i;
    weight=c;
}
adjacencylist::adjacencylist(int num, bool dir){
    elementnum = num;
    direction = dir;
    graph = new one_point[elementnum]();
    for(int i=0;i<elementnum;i++)
        graph[i].content = i+1;
}
void adjacencylist::insert(int i, int j, int weight){
    one_point *p = new one_point(j,weight);
    one_point *look = &graph[i-1];
    while(look->next!=nullptr){
        look =look->next;
    }
    look->next = p;
    if(!direction){
        one_point *p = new one_point(i,weight);
        one_point *look = &graph[j-1];
        while(look->next!=nullptr){
            look =look->next;
        }
        look->next = p;
    }
}

