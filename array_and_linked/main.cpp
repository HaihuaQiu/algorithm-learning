//
//  main.cpp
//  array_and_linked
//
//  Created by H Q on 2020/1/16.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include <iostream>
#include "first.hpp"
#include "second.hpp"
using namespace std;
void test_arr_dynamic();
void test_arr_order();
void combine1();
void test_sll();
void test_dll();
void tets_cll();
void test_reverse_list();
void combine2();
void findmidnode();
int main(int argc, const char * argv[]) {
    // insert code here...
    //test_arr_dynamic();
    //test_arr_order();
    //combine1();
    
    //test_sll();
    //test_dll();
    //tets_cll();
    //test_reverse_list();
    //combine2();
    //findmidnode();
    return 0;
}
void test_arr_dynamic(){
    arr_dynamic arr;
    cout<<arr.length<<endl;
    for(int i=0;i<10;i++){
        arr.add(i);
    }
    for(int i=0;i<arr.length;i++){
        cout<<arr.a[i]<<" ";
    }
    cout<<endl;

    arr.add(10);
    for(int i=0;i<arr.length;i++){
        cout<<arr.a[i]<<" ";
    }
    cout<<endl;

    arr.del(0);
    for(int i=0;i<arr.length;i++){
        cout<<arr.a[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<5;i++){
        arr.del(0);
    }
    for(int i=0;i<arr.length;i++){
        cout<<arr.a[i]<<" ";
    }
    cout<<endl;
}

void test_arr_order(){
    arr_order arr;
    cout<<arr.count<<endl;
    for(int i=9;i>=0;i--){
        cout<<arr.add(i);
    }
    cout<<endl;
    
    for(int i=0;i<arr.count;i++){
        cout<<arr.a[i]<<" ";
    }
    cout<<endl;
    
    cout<<arr.add(10)<<endl;
    
    cout<<arr.count<<endl;
    
    cout<<arr.del(9.9)<<endl;
    cout<<arr.count<<endl;
    
    for(int i=0;i<5;i++){
        arr.del(i);
    }
    cout<<arr.count<<endl;
    for(int i=0;i<arr.count;i++){
        cout<<arr.a[i]<<" ";
    }
    cout<<endl;
}
void combine1(){
    int test1[5]={1,3,5};
    int test2[5]={2,4,9};
    arr_order a1,b1;
    for(int i=0;i<3;i++){
        a1.add(test1[i]);
        b1.add(test2[i]);
    }
    int p[a1.count+b1.count];
    int i=0,j=0,index=0;
    while(true){
        if(a1.a[i]>=b1.a[j]){
            p[index]=b1.a[j];
            j++;
        }else{
            p[index]=a1.a[i];
            i++;
        }
        index++;
        if(i==a1.count){
            for(int k=j;k<b1.count;k++){
                p[index]=b1.a[k];
                index++;
            }
            break;
        }
        if(j==b1.count){
            for(int k=i;k<a1.count;k++){
                p[index]=a1.a[k];
                index++;
            }
            break;
        }
    }
    for(int i=0;i<6;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
void test_sll(){
    sll linklist;
    for(int i=0;i<10;i++)
        linklist.add(new one_point(i));
    linklist.add(new one_point(11));
    linklist.add(new one_point(10));
    one_point *p=linklist.head;
    for(int i=0;i<12;i++){
        if(p->next!=nullptr){
            cout<<p->next->content<<" ";
            p=p->next;
        }
    }
    cout<<endl;
    linklist.del(3);
    linklist.del(10);
    linklist.del(11);
    
    p=linklist.head;
    for(int i=0;i<12;i++){
        if(p->next!=nullptr){
            cout<<p->next->content<<" ";
            p=p->next;
        }
    }
    cout<<endl;
}
void test_dll(){
    dll linklist;
    for(int i=0;i<10;i++)
        linklist.add(new two_point(i));
    linklist.add(new two_point(11));
    linklist.add(new two_point(10));
    two_point *p=linklist.head;
    for(int i=0;i<12;i++){
        if(p->right!=nullptr){
            cout<<p->right->content<<" ";
            p=p->right;
        }
    }
    cout<<endl;
    cout<<p->content<<" ";
    for(int i=0;i<11;i++){
        if(p->left!=nullptr){
            cout<<p->left->content<<" ";
            p=p->left;
        }
    }
    cout<<endl;
    
    linklist.del(3);
    linklist.del(10);
    linklist.del(11);
    
    p=linklist.head;
    for(int i=0;i<12;i++){
        if(p->right!=nullptr){
            cout<<p->right->content<<" ";
            p=p->right;
        }
    }
    cout<<endl;
    cout<<p->content<<" ";
    for(int i=0;i<11;i++){
        if(p->left!=nullptr &&p->left->left!=nullptr){
            cout<<p->left->content<<" ";
            p=p->left;
        }
    }
    cout<<endl;
}
void tets_cll(){
    cll linklist;
    for(int i=0;i<10;i++)
        linklist.add(new one_point(i));
    one_point *p=linklist.head;
    for(int i=0;i<20;i++){
        cout<<p->next->content<<" ";
        p=p->next;
    }
    cout<<endl;
    p=linklist.head;
    for(int i=0;i<10;i++)
        linklist.del(i);
    for(int i=0;i<20;i++){
        if(p->next!=nullptr){
            cout<<p->next->content<<" ";
            p=p->next;
            
        }
    }
    cout<<endl;
}

void test_reverse_list(){
    sll linklist;
    for(int i=0;i<10;i++)
        linklist.add(new one_point(i));
    
    one_point *temp= nullptr;//left
    one_point *head = linklist.head->next;//mid
    one_point *en=head->next;//right
    while(en!=nullptr){
        head->next=temp;
        temp = head;
        head = en;
        en = en->next;
    }
    head->next=temp;
    linklist.head->next=head;
    for(int i=0;i<10;i++){
        cout<<linklist.head->next->content<<" ";
        linklist.head=linklist.head->next;
    }
    cout<<endl;
}
void combine2(){
    sll s1,s2,s3;
    
    for(int i=0;i<3;i++){
        s1.add(new one_point(i*2));
        s2.add(new one_point(i*2+1));
    }
    one_point * p1 = s1.head->next;
    one_point * p2 = s2.head->next;
    one_point * p3 = s3.head;
    while(true){
        if(p1->content>p2->content){
            p3->next=new one_point(p2->content);
            p2=p2->next;
        }
        else{
            p3->next=new one_point(p1->content);
            p1=p1->next;
        }
        p3=p3->next;
        if(p1==nullptr){
            while(p2!=nullptr){
                p3->next=new one_point(p2->content);
                p2=p2->next;
                p3=p3->next;
            }
            break;
        }
        if(p2==nullptr){
            while(p1!=nullptr){
                p3->next=new one_point(p1->content);
                p1=p1->next;
                p3=p3->next;
            }
            break;
        }
    }
    
    for(int i=0;i<6;i++){
        cout<<s3.head->next->content<<" ";
        s3.head=s3.head->next;
    }
    cout<<endl;
}
void findmidnode(){
    sll s1;
    for(int i=1;i<5;i++){
        s1.add(new one_point(i));
    }
    s1.add(new one_point(5));
    one_point *halfstart=s1.head->next,*start=s1.head->next;
    while(start->next!=nullptr && start->next->next!=nullptr){
        start=start->next->next;
        halfstart=halfstart->next;
    }
    cout<<halfstart->content<<endl;
}
