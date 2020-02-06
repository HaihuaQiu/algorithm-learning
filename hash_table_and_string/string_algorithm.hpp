//
//  string_algorithm.hpp
//  hash_table_and_string
//
//  Created by H Q on 2020/1/31.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef string_algorithm_hpp
#define string_algorithm_hpp

#include <stdio.h>
struct trinode{
    char data;
    trinode *arr[26];
    trinode(char c);
};
class tritree{
public:
    trinode* head = new trinode('/');
    void insert(char s[]);
    bool find(char s[]);
};

void string_match(char mainchar[], char modechar[]);
#endif /* string_algorithm_hpp */
