//
//  main.cpp
//  hash_table_and_string
//
//  Created by H Q on 2020/1/31.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include <iostream>
#include "hash_table.hpp"
#include "string_algorithm.hpp"
using namespace std;
void test_hash_table();
void test_hash_lru();
void test_tri_tree();
void test_string_match();
int main(int argc, const char * argv[]) {
    // insert code here...
    //test_hash_table();
    //test_hash_lru();
    //test_tri_tree();
    //test_string_match();
    return 0;
}
void test_hash_table(){
    hash_table h;
    for(int i=0;i<10;i++){
        one_point p = h.a[i];
        cout<<p.content<<" ";
    }
    cout<<endl;
    for(int i=0;i<21;i++)
        cout<<h.add(i)<<" ";
    cout<<endl;
    for(int i=0;i<20;i++)
        cout<<h.search(i)<<" ";
    cout<<endl;
    for(int i=0;i<10;i++)
        cout<<h.del(i)<<" ";
    cout<<endl;
}
void test_hash_lru(){
    lru h;
    for(int i=0;i<10;i++){
        three_point p = h.hash_table[i];
        cout<<p.content<<" ";
    }
    cout<<endl;
    for(int i=0;i<15;i++)
        cout<<h.add(i)<<" ";
    cout<<endl;
    for(int i=15;i<20;i++)
        cout<<h.add(i)<<" ";
    cout<<endl;
    for(int i=19;i>=0;i--)
        cout<<h.search(i)<<" ";
    cout<<endl;
    for(int i=0;i<11;i++)
        cout<<h.del(i)<<" ";
    cout<<endl;
}
void test_tri_tree(){
    char s[][6] = {"how","hi","her","hello","so","see"};
    tritree tree;
    for(int i=0;i<6;i++)
        tree.insert(s[i]);
    cout<<tree.find(s[1])<<" "<<endl;
    cout<<tree.find(s[5])<<" "<<endl;
    cout<<tree.find("he")<<" "<<endl;
}
void test_string_match(){
    char mainchar[]="1234561234589";
    char modechar[]="345";
    string_match(mainchar, modechar);
    cout<<endl;
}
