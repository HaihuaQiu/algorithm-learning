//
//  dynamic_programming.cpp
//  diviconquer_backtracking_and_dynamic_programming
//
//  Created by H Q on 2020/2/4.
//  Copyright © 2020年 H Q. All rights reserved.
//

#include "dynamic_programming.hpp"
#include "iostream"
using namespace std;
//zero_one_package
//状态表法
void zero_one_package_dp(int* weight, int n, const int limited){
    int maxWeight=-100;
    bool state[limited+1];
    for(int i=0;i<limited+1;i++)
        state[i]=false;
    state[0] =true;
    state[weight[0]]=true;
 
    for(int i=1;i<n;i++){
        for(int j=limited-weight[i];j>=0;j--)
            if(state[j]){
                state[j+weight[i]]=true;
            }
    }
    for(int i=limited;i>=0;i--)
        if(state[i]){
            maxWeight=i;
            break;
        }
    cout<<maxWeight<<endl;
}

int minPathSum(int grid[][4],int n){
    //表格状态初始化
    for(int i=0;i<n-1;i++)
        grid[0][i+1] += grid[0][i];
    for(int i=0;i<n-1;i++)
        grid[i+1][0] += grid[i][0];
    //填表格
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
            //状态方程
            grid[i][j]+=min(grid[i-1][j], grid[i][j-1]);
    return grid[n-1][n-1];
}

int min(int a,int b, int c){
    int refer;
    if(a<b){
        refer=a;
    }else{
        refer =b;
    }
    if(refer>c){
        refer=c;
    }
    return refer;
}
int shortestLevensteinEditDistance(char a[], int m, char b[], int n){
    int mindist[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            mindist[i][j]=0;
    for(int j=0;j<n;j++){
        if(a[0]==b[j]){
            mindist[0][j]=j;
        }else if(j!=0){
            mindist[0][j]=mindist[0][j-1]+1;
        }else{
            mindist[0][j]=1;
        }
    }
    for(int j=0;j<m;j++){
        if(b[0]==a[j]){
            mindist[j][0]=j;
        }else if(j!=0){
            mindist[j][0]=mindist[j-1][0]+1;
        }else{
            mindist[j][0]=1;
        }
    }
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++){
            int temp1=mindist[i-1][j]+1;
            int temp2=mindist[i][j-1]+1;
            if(a[i]==b[j]){
                mindist[i][j]=min(temp1,temp2,mindist[i-1][j-1]);
            }else{
                mindist[i][j]=min(temp1,temp2,mindist[i-1][j-1]+1);
            }
        }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mindist[i][j]<<" ";
        }
        cout<<endl;
    }
    return mindist[m-1][n-1];
}

int max(int a,int b, int c){
    int refer;
    if(a<b){
        refer=b;
    }else{
        refer =a;
    }
    if(refer<c){
        refer=c;
    }
    return refer;
}
int longestCommonStringDistance(char a[], int m, char b[], int n){
    int maxlcs[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            maxlcs[i][j]=0;
    for(int j=0;j<n;j++){
        if(a[0]==b[j]){
            maxlcs[0][j]=1;
        }else if(j!=0){
            maxlcs[0][j]=maxlcs[0][j-1];
        }else{
            maxlcs[0][j]=0;
        }
    }
    for(int j=0;j<m;j++){
        if(b[0]==a[j]){
            maxlcs[j][0]=1;
        }else if(j!=0){
            maxlcs[j][0]=maxlcs[j-1][0];
        }else{
            maxlcs[j][0]=0;
        }
    }
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++){
            int temp1=maxlcs[i-1][j];
            int temp2=maxlcs[i][j-1];
            if(a[i]==b[j]){
                maxlcs[i][j]=max(temp1,temp2,maxlcs[i-1][j-1]+1);
            }else{
                maxlcs[i][j]=max(temp1,temp2,maxlcs[i-1][j-1]);
            }
        }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<maxlcs[i][j]<<" ";
        }
        cout<<endl;
    }
    return maxlcs[m-1][n-1];
}

//最长递增子序列
void mostIncreseSubstring(int a[], int n){
    int max[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            max[i][j]=0;
    max[0][0]=1;
    //index是子串的尾部位置，subindex是子串中具有递增序列的每一个尾部位置。
    for(int index=1;index<n;index++){
        for(int subindex=0; subindex<index;subindex++){
            max[index][subindex]=max[index-1][subindex];
            if(a[index]> a[subindex]){//求最值
                if(max[index][index]<max[index-1][subindex]+1)
                    max[index][index]= max[index-1][subindex]+1;
            }
            else{
                if(max[index][index]==0)
                    max[index][index]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<max[i][j]<<" ";
        cout<<endl;
        
    }
    //从后往前输出。
    int maxvalue=-100;
    int index=-1;
    for(int i=0;i<n;i++)
        if(maxvalue<max[n-1][i]){
            maxvalue=max[n-1][i];
            index = i;
        }
    cout<<a[index]<<" ";
    for(int i=n-2;i>=0;i--){
        if(maxvalue==max[i][i]){
            continue;
        }
        maxvalue--;
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
