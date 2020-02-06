//
//  string_algorithm.cpp
//  hash_table_and_string
//
//  Created by H Q on 2020/1/31.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "string_algorithm.hpp"
#include "iostream"

trinode::trinode(char c){
    data = c;
    for(int i=0;i<26;i++)
        arr[i]=nullptr;
}
void tritree::insert(char s[]){
    int i =0;
    trinode *point = head;
    while(s[i]!='\0'){
        int index =s[i]-'a';
        if(point->arr[index]==nullptr){
            trinode *p = new trinode(s[i]);
            point->arr[index] = p;
        }
        point = point->arr[index];
        i++;
    }
}
bool tritree::find(char s[]){
    int i =0;
    trinode *point = head;
    while(s[i]!='\0'){
        int index =s[i]-'a';
        if(point->arr[index]==nullptr){
            return false;
        }
        point = point->arr[index];
        i++;
    }
    for(int i = 0;i<26;i++)
        if(point->arr[i]!=nullptr)
            return false;
    return true;
}

void string_match(char mainchar[], char modechar[]){
    int i =0;
    while(mainchar[i]!='\0'){
        int j=0;
        while(modechar[j]!='\0'){
            if(mainchar[i+j]==modechar[j])
                j++;
            else
                break;
        }
        if(modechar[j]=='\0'){
            std::cout<<i<<" ";
        }
        i++;
    }
}
