//
//  main.cpp
//  binary_tree_and_heap
//
//  Created by H Q on 2020/2/1.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include <iostream>
#include "binary_tree.hpp"
#include "heap.hpp"
using namespace std;
void test_binary_tree();
void test_search_presuc_node();
void test_all_traversal();
void test_bigheap_smallheap();
void test_bigheap_sort();
void test_merge_K_orderarrays();
void test_top_K(double k, int l);
int main(int argc, const char * argv[]) {
    // insert code here...
    //test_binary_tree();
    //test_search_presuc_node();
    //test_all_traversal();
    //test_bigheap_smallheap();
    //test_bigheap_sort();
    //test_merge_K_orderarrays();
    //test_top_K(0.7, 100);
    //test_top_K(0.5, 100);
    //test_top_K(0.7, 200);
    return 0;
}
void test_binary_tree(){
    binary_tree tree;
    tree.find(4);
    tree.insert(13);
    tree.insert(10);
    tree.insert(16);
    tree.insert(9);
    tree.insert(11);
    tree.insert(14);
    tree.insert(12);
    tree.insert(11);
    tree.find(4);
    tree.find(13);
    tree.find(11);
    cout<<tree.remove(4)<<endl;
    cout<<tree.remove(13)<<endl;
    cout<<tree.remove(11)<<endl;
}
void test_search_presuc_node(){
    binary_tree tree;
    tree.insert(13);
    tree.insert(10);
    tree.insert(16);
    tree.insert(9);
    tree.insert(11);
    tree.insert(14);
    cout<<tree.searchPrecursorNode(13)<<endl;
    cout<<tree.searchSuccessorNode(13)<<endl;
    cout<<tree.searchPrecursorNode(10)<<endl;
    cout<<tree.searchSuccessorNode(10)<<endl;
    cout<<tree.searchPrecursorNode(16)<<endl;
    cout<<tree.searchSuccessorNode(16)<<endl;
}
void test_all_traversal(){
    binary_tree tree;
    tree.insert(13);
    tree.insert(10);
    tree.insert(16);
    tree.insert(9);
    tree.insert(11);
    tree.insert(14);
    
    tree.preOrder(tree.head);
    cout<<endl;
    tree.inOrder(tree.head);
    cout<<endl;
    tree.postOrder(tree.head);
    cout<<endl;
    tree.layerOrder(tree.head);
    cout<<endl;
}
void test_bigheap_smallheap(){
    bigheap bh(10);
    smallheap sh(10);
    for(int i=10;i>0;i--){
        bh.insert(i);
    }
    for(int i=1;i<11;i++){
        sh.insert(i);
    }
    for(int i=1;i<11;i++){
        cout<<bh.arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<11;i++){
        cout<<sh.arr[i]<<" ";
    }
    cout<<endl;
    bh.removeElement();
    bh.removeElement();
    sh.removeElement();
    sh.removeElement();
    for(int i=1;i<=bh.count;i++){
        cout<<bh.arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=sh.count;i++){
        cout<<sh.arr[i]<<" ";
    }
    cout<<endl;
}
void test_bigheap_sort(){
    bigheap bh(10);
    int a[10];
    for(int i=9;i>=0;i--)
        a[i]=i+1;
    bh.build(a, 10);
    for(int i=1;i<=bh.count;i++){
        cout<<bh.arr[i]<<" ";
    }
    cout<<endl;
    bh.sort();
    for(int i=1;i<=bh.count;i++){
        cout<<bh.arr[i]<<" ";
    }
    cout<<endl;
}
void test_merge_K_orderarrays(){
    smallheap sh(10);
    int a[5][5];
    int b[25];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            a[i][j]=i+5*(j+1);
    }
    int k=0;
    for(int j=0;j<5;j++)
        sh.insert(a[j][0]);
    for(int i=1;i<=sh.count;i++){
        cout<<sh.arr[i]<<" ";
    }
    cout<<endl;
    while(k<25){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++)
                if(sh.arr[1]==a[i][j]){
                    b[k]=sh.arr[1];
                    sh.removeElement();
                    if(j+1<5)
                        sh.insert(a[i][j+1]);
                    for(int i=1;i<=sh.count;i++){
                        cout<<sh.arr[i]<<" ";
                    }
                    cout<<endl;
                    k++;
                }
        }
    }
    for(int j=0;j<25;j++)
        cout<<b[j]<<" ";
    cout<<endl;
}
void test_top_K(double k, int l){
    int length=l/2;
    bigheap bh(l);
    smallheap sh(l);
    for(int i=1;i<=length;i++){
        bh.insert(i);
    }
    for(int i=length+1;i<=l;i++){
        sh.insert(i);
    }
    int num=bh.count-k*l;//>0则说明bigheap元素多了，<0则说明smallheap元素多了。
    if(num>0){
        while(num>0){
            sh.insert(bh.arr[1]);
            bh.removeElement();
            num--;
        }
    }else if(num<0){
        while(num<0){
            bh.insert(sh.arr[1]);
            sh.removeElement();
            num++;
        }
    }
    cout<<bh.arr[1]<<" "<<sh.arr[1]<<endl;
}
