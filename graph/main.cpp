//
//  main.cpp
//  graph
//
//  Created by H Q on 2020/2/2.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include <iostream>
#include "graph_representation.hpp"
#include "dfs_and_bfs.hpp"
#include "dijkstra_and_a*.hpp"
using namespace std;
void test_adjacencymatrix();
void test_adjacencylinklist();
void test_bfs_dfs();
void test_priority_queue();
void test_dijkstra_and_astar();
int main(int argc, const char * argv[]) {
    // insert code here...
    //test_adjacencymatrix();
    //test_adjacencylinklist();
    //test_bfs_dfs();
    //test_priority_queue();
    //test_dijkstra_and_astar();
    return 0;
}
void test_adjacencymatrix(){
    adjacencymatrix m1(4,false);//无向无权图
    m1.insert(1, 3);
    m1.insert(1, 2);
    m1.insert(2, 3);
    m1.insert(2, 4);
    m1.insert(3, 4);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<m1.graph[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    adjacencymatrix m2(4,true);//有向无权图
    m2.insert(3, 1);
    m2.insert(1, 2);
    m2.insert(4, 2);
    m2.insert(4, 3);
    m2.insert(3, 2);
    m2.insert(2, 3);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<m2.graph[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    adjacencymatrix m3(4,false);//无向有权图
    m3.insert(3, 1, 3);
    m3.insert(1, 2, 5);
    m3.insert(4, 2, 6);
    m3.insert(4, 3, 1);
    m3.insert(2, 3, 2);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<m3.graph[i][j]<<" ";
        cout<<endl;
    }
}
void test_adjacencylinklist(){
    adjacencylist m1(5,true);//有向无权图
    for(int i=0;i<m1.elementnum;i++)
        cout<<m1.graph[i].content<<" ";
    cout<<endl;
    m1.insert(1, 2);
    m1.insert(2, 3);
    m1.insert(2, 5);
    m1.insert(2, 4);
    m1.insert(4, 1);
    m1.insert(4, 2);
    m1.insert(5, 4);
    m1.insert(5, 3);
    for(int i=0;i<m1.elementnum;i++){
        cout<<m1.graph[i].content<<": ";
        one_point *p = m1.graph[i].next;
        while(p!=nullptr){
            cout<<p->content<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    adjacencylist m2(5,false);//无向无权图
    for(int i=0;i<m1.elementnum;i++)
        cout<<m2.graph[i].content<<" ";
    cout<<endl;
    m2.insert(1, 2);
    m2.insert(2, 3);
    m2.insert(2, 5);
    m2.insert(2, 4);
    m2.insert(4, 1);
    m2.insert(5, 4);
    m2.insert(5, 3);
    for(int i=0;i<m2.elementnum;i++){
        cout<<m2.graph[i].content<<": ";
        one_point *p = m2.graph[i].next;
        while(p!=nullptr){
            cout<<p->content<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    adjacencylist m3(5,true);//有向有权图
    for(int i=0;i<m3.elementnum;i++)
        cout<<m3.graph[i].content<<" ";
    cout<<endl;
    m3.insert(1, 2, 1);
    m3.insert(2, 3, 2);
    m3.insert(2, 5, 3);
    m3.insert(2, 4, 4);
    m3.insert(4, 1, 5);
    m3.insert(4, 2, 6);
    m3.insert(5, 4, 7);
    m3.insert(5, 3, 8);
    for(int i=0;i<m3.elementnum;i++){
        cout<<m3.graph[i].content<<": ";
        one_point *p = m3.graph[i].next;
        while(p!=nullptr){
            cout<<p->weight<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
void test_bfs_dfs(){
    adjacencylist m(8,false);//无向无权图
    m.insert(1, 2);
    m.insert(1, 4);
    m.insert(2, 3);
    m.insert(2, 5);
    m.insert(3, 6);
    m.insert(4, 5);
    m.insert(5, 6);
    m.insert(5, 7);
    m.insert(6, 8);
    m.insert(7, 8);
    cout<<"bfs:"<<endl;
    bfs(1, 7, m);
    cout<<endl;
    bfs(1, 8, m);
    cout<<endl;
    bfs(5, 8, m);
    cout<<endl;
    cout<<"dfs:"<<endl;
    for(int i=1;i<=8;i++){
        cout<<i<<": ";
        dfs(1, i, m);
        cout<<endl;
    }
    cout<<7<<": ";
    dfs(2, 7, m);
    cout<<endl;
}
void test_priority_queue(){
    priority_queue q(10);
    q.insert(new vertex(2,10));
    q.insert(new vertex(1,5));
    q.insert(new vertex(10,0));
    q.insert(new vertex(0,6));
    q.insert(new vertex(5,1));
    q.insert(new vertex(4,8));
    for(int i=1;i<=q.count;i++){
        cout<<q.arr[i].dist<<" ";
    }
    cout<<endl;
    q.removeElement();
    q.removeElement();
    for(int i=1;i<=q.count;i++){
        cout<<q.arr[i].dist<<" ";
    }
    cout<<endl;
    q.update(new vertex(2,2));
    q.update(new vertex(4,2));
    for(int i=1;i<=q.count;i++){
        cout<<q.arr[i].dist<<" ";
    }
    cout<<endl;
    int num=q.count;
    for(int i=1;i<=num;i++){
        q.removeElement();;
    }
    cout<<q.empty()<<" "<<q.count<<endl;
}
void test_dijkstra_and_astar(){
    cout<<"dijkstra: "<<endl;
    adjacencylist m3(6,true);//有向有权图
    m3.insert(1, 2, 10);
    m3.insert(2, 3, 15);
    m3.insert(2, 4, 2);
    m3.insert(3, 6, 5);
    m3.insert(4, 3, 1);
    m3.insert(4, 6, 12);
    m3.insert(1, 5, 15);
    m3.insert(5, 6, 10);
    for(int i=0;i<m3.elementnum;i++){
        cout<<m3.graph[i].content-1<<": ";
        one_point *p = m3.graph[i].next;
        while(p!=nullptr){
            cout<<p->content-1<<"-"<<p->weight<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    dijkstra(1, 6, m3);
    
    cout<<endl;
    
    cout<<"astar: "<<endl;
    adjacencylist m4(11,false);//无向有权图
    m4.insert(1, 2, 20);
    m4.insert(2, 3, 20);
    m4.insert(3, 4, 10);
    m4.insert(1, 5, 60);
    m4.insert(1, 6, 60);
    m4.insert(1, 7, 60);
    m4.insert(5, 9, 50);
    m4.insert(6, 9, 50);
    m4.insert(6, 10, 80);
    m4.insert(9, 10, 50);
    m4.insert(6, 11, 50);
    m4.insert(10,11, 60);
    m4.insert(7, 8, 70);
    for(int i=0;i<m4.elementnum;i++){
        cout<<m4.graph[i].content-1<<": ";
        one_point *p = m4.graph[i].next;
        while(p!=nullptr){
            cout<<p->content-1<<"-"<<p->weight<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    cout<<endl;
    int x[11]={320,300,280,270,320,360,320,370,350,390,400};
    int y[11]={630,630,625,630,700,620,590,580,730,690,620};
    astar(1, 11, m4, x, y);
}
