//
//  binary_tree.hpp
//  binary_tree_and_heap
//
//  Created by H Q on 2020/2/1.
//  Copyright © 2020年 H Q. All rights reserved.
//

#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <stdio.h>
struct two_node{
    int content;
    two_node *left=nullptr;
    two_node *right=nullptr;
    two_node(int c);
};

class binary_tree{
public:
    two_node *head=nullptr;
    void insert(int content);
    bool remove(int content);
    void find(int content);
    int searchPrecursorNode(int content);
    int searchSuccessorNode(int content);
    void preOrder(two_node * root);
    void inOrder(two_node * root);
    void postOrder(two_node * root);
    void layerOrder(two_node * root);
};
#endif /* binary_tree_hpp */
