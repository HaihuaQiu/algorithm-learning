//
//  dfs_and_bfs.cpp
//  graph
//
//  Created by H Q on 2020/2/2.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "dfs_and_bfs.hpp"
#include "queue"
#include "iostream"
using namespace std;
void print(int *pre,int start, int target){
    if(start==target){
        cout<<start<<" ";
        return;
    }
    print(pre,start,pre[target]);
    cout<<target<<" ";
}
void bfs( int start, int target, adjacencylist m){
    if(start==target)
        return;
    int *prepoint= new int[m.elementnum]();
    bool *visited = new bool[m.elementnum];
    bool found=false;
    queue<one_point*> q;
    one_point* p = &m.graph[start-1];
    q.push(p);
    visited[start-1] = true;
    while(!q.empty()){
        one_point* s = q.front();
        if(s->content == target){
            found=true;
            break;
        }
        one_point* sp= s;
        while(s!=nullptr){
            s=s->next;
            if(s!=nullptr && !visited[s->content-1]){
                q.push(&m.graph[s->content-1]);
                prepoint[s->content-1]=sp->content-1;
                visited[s->content-1] = true;
            }
            
        }
        q.pop();
    }
    if(found){
        print(prepoint,start-1,target-1);
        return;
    }
}
void print1(int *pre,int start, int target){
    if(start==target){
        cout<<start+1<<" ";
        return;
    }
    print1(pre,start,pre[target]);
    cout<<target+1<<" ";
}
void recurdfs(int start, int target, adjacencylist m, int *prepoint,bool *visited, bool* found){
    if(m.graph[start-1].content==target){
        *found =true;
        return;
    }
    if (visited[start-1])
        return;
    one_point* s = &m.graph[start-1];
    visited[start-1] = true;
    while(s!=nullptr){
        s=s->next;
        if(s!=nullptr && !visited[s->content-1]){
            recurdfs(s->content, target, m, prepoint, visited,found);
            if(*found){
                prepoint[s->content-1]=start-1;
                return;
            }
            //visited[s->content-1]=false;
        }
        
    }
}
void dfs(int start, int target, adjacencylist m){
    if(start==target){
        cout<<start<<" ";
        return;
    }
    int *prepoint= new int[m.elementnum]();
    bool *visited = new bool[m.elementnum];
    bool found=false;
    recurdfs(start, target, m, prepoint, visited, &found);
    if(found){
        print1(prepoint,start-1,target-1);
    }else{
        cout<<"no found!"<<endl;
    }
}
