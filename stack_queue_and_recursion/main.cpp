//
//  main.cpp
//  stack_queue_and_recursion
//
//  Created by H Q on 2020/1/18.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
#include "recurision.hpp"
using namespace std;
void test_stack_arr();
void test_stack_linklist();
void test_stack_simulation();
void test_queue_arr();
void test_queue_linklist();
void test_queue_circle();
void test_fibonaci();
void test_fj();
void test_arrange();
int main(int argc, const char * argv[]) {
    // insert code here...
    //test_stack_arr();
    //test_stack_linklist();
    //test_stack_simulation();
    //test_queue_arr();
    //test_queue_linklist();
    //test_queue_circle();
    //test_fibonaci();
    //test_fj();
    test_arrange();
    return 0;
}
void test_stack_arr(){
    stack_arr stack;
    for(int i=1;i<8;i++)
        cout<<stack.push(i)<<" ";
    cout<<endl;
    cout<<stack.push(10)<<" "<<endl;
    for(int i=0;i<10;i++){
        int k = stack.pop();
        if(k==-1)
            break;
        else
            cout<<k<<" ";
    }
    cout<<endl;
    cout<<stack.pop()<<" "<<endl;
}
void test_stack_linklist(){
    stack_linklist stack;
    for(int i=1;i<8;i++)
        cout<<stack.push(i)<<" ";
    cout<<endl;
    cout<<stack.push(10)<<" "<<endl;
    for(int i=0;i<15;i++){
        int k = stack.pop();
        if(k==-1)
            continue;
        else
            cout<<k<<" ";
    }
    cout<<endl;
}
void test_stack_simulation(){
    stack_linklist stack1,stack2;
    //前进
    for(int i=1;i<8;i++)
        cout<<stack1.push(i)<<" ";
    cout<<endl;
    
    //后退
    for(int i=0;i<4;i++)
        cout<<stack2.push(stack1.pop())<<" ";
    cout<<endl;
    //前进
    for(int i=0;i<4;i++)
        cout<<stack1.push(stack2.pop())<<" ";
    cout<<endl;
}
void test_queue_arr(){
    queue_arr queue;
    for(int i=0;i<10;i++)
        cout<<queue.enqueue(i)<<" ";
    cout<<endl;
    cout<<queue.enqueue(10)<<" "<<endl;
    for(int i=0;i<10;i++){
        int k = queue.dequeue();
        if(k==-1)
            break;
        else
            cout<<k<<" ";
    }
    cout<<endl;
    cout<<queue.dequeue()<<" "<<endl;
    cout<<queue.start<<" "<<queue.end<<endl;
    cout<<queue.enqueue(5)<<endl;
    cout<<queue.start<<" "<<queue.end<<endl;
}
void test_queue_linklist(){
    queue_linklist queue;
    for(int i=0;i<10;i++)
        cout<<queue.enqueue(i)<<" ";
    cout<<endl;
    cout<<queue.enqueue(10)<<" "<<endl;
    for(int i=0;i<10;i++){
        int k = queue.dequeue();
        if(k==-1)
            break;
        else
            cout<<k<<" ";
    }
    cout<<endl;
    cout<<queue.dequeue()<<" "<<endl;
    cout<<queue.dequeue()<<" "<<endl;
    cout<<queue.start<<" "<<queue.end<<endl;
    cout<<queue.enqueue(5)<<endl;
    cout<<queue.start<<" "<<queue.end<<endl;
}
void test_queue_circle(){
    circle_queue queue;
    for(int i=0;i<10;i++)
        cout<<queue.enqueue(i)<<" ";
    cout<<endl;
    cout<<queue.enqueue(10)<<" "<<endl;
    for(int i=0;i<10;i++){
        int k = queue.dequeue();
        if(k==-1)
            break;
        else
            cout<<k<<" ";
    }
    cout<<endl;
    cout<<queue.dequeue()<<" "<<endl;
    cout<<queue.dequeue()<<" "<<endl;
    cout<<queue.start<<" "<<queue.end<<endl;
    cout<<queue.enqueue(5)<<endl;
    cout<<queue.start<<" "<<queue.end<<endl;
}
void test_fibonaci(){
    for (int i=0;i<=10;i++)
        cout<<fibonaci(i)<<" ";
    cout<<endl;
}
void test_fj(){
    for (int i=1;i<=10;i++)
        cout<<fj(i)<<" ";
    cout<<endl;
}
void test_arrange(){
    string refer = "1234";
    bool* used = new bool[refer.length()];
    arrange("", refer, 0, used);
}
