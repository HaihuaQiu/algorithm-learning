//
//  binary_tree.cpp
//  binary_tree_and_heap
//
//  Created by H Q on 2020/2/1.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "binary_tree.hpp"
#include "iostream"
#include "queue"
two_node::two_node(int c){
    content = c;
}

void binary_tree::insert(int content){
    two_node *p = new two_node(content);
    two_node *search = head;
    if(search==nullptr)
        head=p;
    else{
        while(true){
            if(search->content>p->content){
                if(search->left==nullptr){
                    search->left = p;
                    break;
                }
                search=search->left;
            }
            else{
                if(search->right==nullptr){
                    search->right = p;
                    break;
                }
                search=search->right;
            }
        }
    }
}
void binary_tree::find(int content){
    two_node *search = head;
    if(search==nullptr){
        std::cout<<"-1 "<<std::endl;
        return;
    }
    while(search!=nullptr){
        if(search->content>content){
            search=search->left;
        }
        else{
            if(search->content==content){
                std::cout<<search->content<<" ";
                search=search->right;
                while(search!=nullptr){
                    if(search->content==content){
                        std::cout<<search->content<<" ";
                    }
                    search=search->left;
                }
                std::cout<<std::endl;
                return;
            }
            search=search->right;
        }
    }
    std::cout<<"-1 "<<std::endl;
}

bool del_last(two_node* head, int content){
    two_node *search = head;
    if(search==nullptr){
        return false;
    }
    two_node *search_p=nullptr;
    while(search!=nullptr){
        if(search->content>content){
            search_p=search;
            search=search->left;
        }
        else{
            if(search->content==content){
                if(search->left == nullptr && search->right == nullptr){
                    if(search_p->left==search)
                        search_p->left=nullptr;
                    if(search_p->right==search)
                        search_p->right=nullptr;
                    delete search;
                    return true;
                }else if((search->left != nullptr && search->right == nullptr)||(search->right != nullptr && search->left == nullptr)){
                    if(search_p->left==search){
                        if(search->left != nullptr){
                            search_p->left=search->left;
                        }
                        else{
                            search_p->left=search->right;
                        }
                    }
                    if(search_p->right==search){
                        if(search->left != nullptr){
                            search_p->right=search->left;
                        }
                        else{
                            search_p->right=search->right;
                        }
                    }
                    delete search;
                    return true;
                }else if(search->left != nullptr && search->right != nullptr){
                    two_node* state = search;
                    search=search->right;
                    while(search->left!=nullptr){
                        search_p=search;
                        search=search->left;
                    }
                    state->content = search->content;
                    if(search_p->left==search)
                        search_p->left=search->right;
                    if(search_p->right==search)
                        search_p->right=search->right;
                    delete search;
                    return true;
                }
            }
            search_p=search;
            search=search->right;
        }
    }
    
    return false;
}
bool binary_tree::remove(int content){
    two_node *search = head;
    bool flag=false;
    while(del_last(search, content)==true){
        flag =true;
        std::cout<<"del! ";
    }
    return flag;
}
int binary_tree::searchPrecursorNode(int content){
    two_node *search = head;
    while(search!=nullptr){
        if(search->content>content){
            search=search->left;
        }
        else{
            if(search->content==content){
                break;
            }
            search=search->right;
        }
    }
    if(search==nullptr || search->left==nullptr)
        return -1;
    search=search->left;
    while(search->right!=nullptr)
        search=search->right;
    return search->content;
}
int binary_tree::searchSuccessorNode(int content){
    two_node *search = head;
    while(search!=nullptr){
        if(search->content>content){
            search=search->left;
        }
        else{
            if(search->content==content){
                break;
            }
            search=search->right;
        }
    }
    if(search==nullptr||search->right==nullptr)
        return -1;
    search=search->right;
    while(search->left!=nullptr)
        search=search->left;
    return search->content;
}
void binary_tree::preOrder(two_node * root){
    if(root==nullptr)
        return;
    std::cout<<root->content<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void binary_tree::inOrder(two_node * root){
    if(root==nullptr)
        return;
    inOrder(root->left);
    std::cout<<root->content<<" ";
    inOrder(root->right);
}
void binary_tree::postOrder(two_node * root){
    if(root==nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->content<<" ";
}
void binary_tree::layerOrder(two_node * root){
    std::queue<two_node*> q;
    q.push(root);
    while(!q.empty()){
        two_node *p= q.front();
        std::cout<<p->content<<" ";
        if(p->left!=nullptr)
            q.push(p->left);
        if(p->right!=nullptr)
            q.push(p->right);
        q.pop();
    }
}
