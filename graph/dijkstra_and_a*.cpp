//
//  dijkstra_and_a*.cpp
//  graph
//
//  Created by H Q on 2020/2/2.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "dijkstra_and_a*.hpp"
#include "iostream"
using namespace std;
vertex::vertex(){
    id=-1;
    dist=1000000;
}
vertex::vertex(int id,int dist){
    this->id = id;
    this->dist = dist;
}

priority_queue::priority_queue(int l){
    count = 0;
    length = l;
    arr = new vertex[length+1];
}
priority_queue::~priority_queue(){
    delete []arr;
}
void priority_queue::insert(vertex* v){
    count++;
    if(count>length){
        count--;
        return;
    }
    int index = count;
    while(index>=1){
        if(index/2>0 && arr[index/2].dist>v->dist){
            arr[index]=arr[index/2];
            arr[index/2]=*v;
            index=index/2;
        }else{
            arr[index]=*v;
            break;
        }
    }
}
void priority_queue::update(vertex* v){
    int index=-1;
    for(int i=1;i<=count;i++){
        if(arr[i].id==v->id){
            index = i;
            break;
        }
    }
    arr[index].dist = v->dist;
    int t = index;
    while(index>=1){
        if(index/2>0 && arr[index/2].dist>v->dist){
            arr[index]=arr[index/2];
            arr[index/2]=*v;
            index=index/2;
        }else{
            arr[index]=*v;
            break;
        }
    }
    
    index =t;
    while(2*index<=count){
        if(arr[index].dist>arr[2*index].dist||(arr[index].dist>arr[2*index+1].dist&&2*index+1<=count)){
            if(2*index+1<=count && arr[2*index].dist>=arr[2*index+1].dist){
                vertex temp = arr[index];
                arr[index] = arr[2*index+1];
                arr[2*index+1]=temp;
                index = 2*index+1;
            }else{
                vertex temp = arr[index];
                arr[index] = arr[2*index];
                arr[2*index]=temp;
                index = 2*index;
            }
        }else{
            break;
        }
    }
}
void priority_queue::removeElement(){
    if(count==0)
        return;
    arr[1] = arr[count];
    //arr[count].dist=10000;
    count--;
    int index = 1;
    
    while(2*index<=count){
        if(arr[index].dist>arr[2*index].dist||(arr[index].dist>arr[2*index+1].dist&&2*index+1<=count)){
            if(2*index+1<=count && arr[2*index].dist>=arr[2*index+1].dist){
                vertex temp = arr[index];
                arr[index] = arr[2*index+1];
                arr[2*index+1]=temp;
                index = 2*index+1;
            }else{
                vertex temp = arr[index];
                arr[index] = arr[2*index];
                arr[2*index]=temp;
                index = 2*index;
            }
        }else{
            break;
        }
    }}

bool priority_queue::empty(){
    return count==0;
}

void print11(int *pre,int start, int target){
    if(start==target){
        cout<<start<<" ";
        return;
    }
    print11(pre,start,pre[target]);
    cout<<target<<" ";
}
void dijkstra( int start, int target, adjacencylist m){
    priority_queue q(m.elementnum);
    bool *visited = new bool[m.elementnum];
    vertex *vert = new vertex[m.elementnum];
    for(int i=0;i<m.elementnum;i++){
        vert[i].id=i+1;
        vert[i].dist=10000;
    }
    int *pre= new int[m.elementnum];
    for(int i=0;i<m.elementnum;i++)
        visited[i]=false;
    vert[start-1].dist=0;
    q.insert(&vert[start-1]);
    visited[start-1]=true;
    while(!q.empty()){
        vertex *p1 = &q.arr[1];
        if(p1->id==target){
            cout<<p1->dist<<endl;
            break;
        }
        for(int i=1;i<=q.count;i++){
            cout<<q.arr[i].id<<":"<<q.arr[i].dist<<"  ";
        }
        cout<<endl;
        one_point* p= &m.graph[p1->id-1];
        long prepoint = p1->dist;
        int pp = p1->id;
        q.removeElement();//会导致p1指向的内容发生改变。
        while(true){
            p=p->next;
            if(p==nullptr)
                break;
            if(p->weight+prepoint<vert[p->content-1].dist){
                pre[p->content-1]= pp-1;
                vert[p->content-1].dist=p->weight+prepoint;
                if(!visited[p->content-1]){
                    q.insert(&vert[p->content-1]);
                    visited[p->content-1]=true;
                }else{
                    q.update(&vert[p->content-1]);
                }
                
            }
        }
        
    }
    print11(pre,start-1, target-1);
    cout<<endl;
}

//astar

vertex_astar::vertex_astar():vertex::vertex(){
    
}
vertex_astar::vertex_astar(int id, int dist, int x, int y):vertex::vertex(id, dist){
    this->x=x;
    this->y=y;
    f = 10000;
}

priority_queue_astar::priority_queue_astar(int l){
    count = 0;
    length = l;
    arr = new vertex_astar[length+1];
}
priority_queue_astar::~priority_queue_astar(){
    delete []arr;
}
void priority_queue_astar::insert(vertex_astar* v){
    count++;
    if(count>length){
        count--;
        return;
    }
    int index = count;
    while(index>=1){
        if(index/2>0 && arr[index/2].f>v->f){
            arr[index]=arr[index/2];
            arr[index/2]=*v;
            index=index/2;
        }else{
            arr[index]=*v;
            break;
        }
    }
}
void priority_queue_astar::update(vertex_astar* v){
    int index=-1;
    for(int i=1;i<=count;i++){
        if(arr[i].id==v->id){
            index = i;
            break;
        }
    }
    arr[index].f -=arr[index].dist;
    arr[index].dist = v->dist;
    arr[index].f +=arr[index].dist;
    int t = index;
    while(index>=1){
        if(index/2>0 && arr[index/2].f>v->f){
            arr[index]=arr[index/2];
            arr[index/2]=*v;
            index=index/2;
        }else{
            arr[index]=*v;
            break;
        }
    }
    
    index =t;
    while(2*index<=count){
        if(arr[index].f>arr[2*index].f||(arr[index].f>arr[2*index+1].f&&2*index+1<=count)){
            if(2*index+1<=count && arr[2*index].f>=arr[2*index+1].f){
                vertex_astar temp = arr[index];
                arr[index] = arr[2*index+1];
                arr[2*index+1]=temp;
                index = 2*index+1;
            }else{
                vertex_astar temp = arr[index];
                arr[index] = arr[2*index];
                arr[2*index]=temp;
                index = 2*index;
            }
        }else{
            break;
        }
    }
}
void priority_queue_astar::removeElement(){
    if(count==0)
        return;
    arr[1] = arr[count];
    //arr[count].dist=10000;
    count--;
    int index = 1;
    
    while(2*index<=count){
        if(arr[index].f>arr[2*index].f||(arr[index].f>arr[2*index+1].f&&2*index+1<=count)){
            if(2*index+1<=count && arr[2*index].f>=arr[2*index+1].f){
                vertex_astar temp = arr[index];
                arr[index] = arr[2*index+1];
                arr[2*index+1]=temp;
                index = 2*index+1;
            }else{
                vertex_astar temp = arr[index];
                arr[index] = arr[2*index];
                arr[2*index]=temp;
                index = 2*index;
            }
        }else{
            break;
        }
    }}

bool priority_queue_astar::empty(){
    return count==0;
}

void astar( int start, int target, adjacencylist m, int *x, int *y){
    priority_queue_astar q(m.elementnum);
    bool *visited = new bool[m.elementnum];
    vertex_astar *vert = new vertex_astar[m.elementnum];
    vert[target-1].x=x[target-1];
    vert[target-1].y=y[target-1];
    for(int i=0;i<m.elementnum;i++){
        vert[i].id=i+1;
        vert[i].dist=10000;
        vert[i].x = x[i];
        vert[i].y = y[i];
        vert[i].f = vert[i].dist+abs(vert[i].x-vert[target-1].x) + abs(vert[i].y-vert[target-1].y);
    }
    int *pre= new int[m.elementnum];
    for(int i=0;i<m.elementnum;i++)
        visited[i]=false;
    vert[start-1].f -=vert[start-1].dist;
    vert[start-1].dist=0;
    vert[start-1].f +=vert[start-1].dist;
    q.insert(&vert[start-1]);
    visited[start-1]=true;
    while(!q.empty()){
        vertex_astar *p1 = &q.arr[1];
        /*dijkstra
        if(p1->id==target){
            cout<<p1->dist<<endl;
            break;
        }
         */
        for(int i=1;i<=q.count;i++){
            cout<<q.arr[i].id<<":"<<q.arr[i].f<<"  ";
        }
        cout<<endl;
        one_point* p= &m.graph[p1->id-1];
        long prepoint = p1->dist;
        int pp = p1->id;
        q.removeElement();//会导致p1指向的内容发生改变。
        while(true){
            p=p->next;
            if(p==nullptr)
                break;
            //astar
            if(p->content==target){
                pre[p->content-1]= pp-1;
                print11(pre,start-1, target-1);
                cout<<endl;
                return;
            }
            if(p->weight+prepoint<vert[p->content-1].dist){
                pre[p->content-1]= pp-1;
                vert[p->content-1].f-=vert[p->content-1].dist;
                vert[p->content-1].dist=p->weight+prepoint;
                vert[p->content-1].f+=vert[p->content-1].dist;
                if(!visited[p->content-1]){
                    q.insert(&vert[p->content-1]);
                    visited[p->content-1]=true;
                }else{
                    q.update(&vert[p->content-1]);
                }
                
            }
        }
        
    }
}
