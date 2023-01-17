#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

const int f=INT_MAX;
const int size=9;
int Graph[size][size]={{f,4,f,f,f,f,8,f,f},
                        {4,f,8,f,f,f,f,11,f},
                        {f,8,f,7,f,4,f,f,2},
                        {f,f,7,f,9,14,f,f,f},
                        {f,f,f,9,f,10,f,f,f},
                        {f,f,4,14,10,f,2,f,f},
                        {f,f,f,f,f,2,f,1,6},
                        {8,11,f,f,f,f,1,f,7},
                        {f,f,2,f,f,f,6,7,f},};

int near[size];
vector <vector<int>> span_tree;
int cost=0;

void find_min_edge(){
    int min_edge=f;
    int s,e;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(Graph[i][j]<min_edge){
                min_edge=Graph[i][j];
                s=i;
                e=j;
            }
        }
    }

    span_tree.push_back({s,e});
    near[s]=-1;
    near[e]=-1;
    cost+=Graph[s][e];
}

void init_near(){
    for(int i=0;i<size;i++){
        
        if(near[i]!=-1){
            if(Graph[span_tree[0][0]][i] <= Graph[span_tree[0][1]][i]){  // comparing dist from already present 2 vertex to new unconnected vertex
                near[i]=span_tree[0][0];  // if 1st vertex is at smaller dist to ith vertex
            }else{
                near[i]=span_tree[0][1];    
            }
        }

    }
}

void prim(){
    while(span_tree.size()!=size-1){  // until we didn't get a spanning tree with V-1 edges
        int s=0,e=0;

        // selecting min dist from near[]  array
        for(int i=0;i<size;i++){
            if(near[i]!=-1){

                if(Graph[near[i]][i] < Graph[s][e]){
                    s=near[i];
                    e=i;
                }
            }
        }

        span_tree.push_back({s,e});
        cost+=Graph[s][e];
        near[e]=-1;

        // upading near[] 
        for(int i=0;i<size;i++){
            if(near[i]!= -1){

                if(Graph[near[i]][i] > Graph[e][i]){
                    near[i]=e;
                }
            }
        }
    }
}

void display(){
    for(int i=0;i<size-1;i++){
        cout<<span_tree[i][0]<<" - "<<span_tree[i][1]<<endl;
    }
    cout<<"min cost = "<<cost;
}

int main(){
    find_min_edge();
    init_near();
    prim();

    display();
}