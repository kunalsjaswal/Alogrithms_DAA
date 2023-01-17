// finding min cost spanning tree
#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int f=INT_MAX;
int cost=0;
const int size=9;

int Graph2[size][size]={{f,25,f,f,f,5,f},
                        {25,f,12,f,f,f,10},
                        {f,12,f,8,f,f,f},
                        {f,f,8,f,16,f,14},
                        {f,f,f,16,f,20,18},
                        {5,f,f,f,20,f,f},
                        {f,10,f,14,18,f,f}};

int Graph[size][size]={{f,4,f,f,f,f,8,f,f},
                        {4,f,8,f,f,f,f,11,f},
                        {f,8,f,7,f,4,f,f,2},
                        {f,f,7,f,9,14,f,f,f},
                        {f,f,f,9,f,10,f,f,f},
                        {f,f,4,14,10,f,2,f,f},
                        {f,f,f,f,f,2,f,1,6},
                        {8,11,f,f,f,f,1,f,7},
                        {f,f,2,f,f,f,6,7,f},};

int near[size]={f};
vector<vector <int>> span_tree;


void find_shortest_edge(){
    // upper triangular
    int min_edge=Graph[0][0];
    span_tree.push_back({0,0});
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(Graph[i][j]<min_edge){
                min_edge=Graph[i][j];
                span_tree[0]={i,j};
            }
        }
    }
    cost+=min_edge;
    near[span_tree[0][0]]=-1;
    near[span_tree[0][1]]=-1;
}


void find_spanning_tree(){

    // updating near array 
    for(int i=0;i<size;i++){
        if(near[i]!=-1){
            if(Graph[span_tree[0][0]][i]<=Graph[span_tree[0][1]][i]){
                near[i]=span_tree[0][0];
            }else{
                near[i]=span_tree[0][1];
            }
        }
    }

    while(span_tree.size()!=size-1){
        int s=0;
        int e=0;

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

        // updating near array 
        near[e]=-1;

        for(int i=0;i<size;i++){
            if(near[i]!=-1){
                if(Graph[e][i]<Graph[near[i]][i]){
                    near[i]=e;
                }
            }
        }
    }
}

void print_result(){
    cout<<"min cost spanning tree edges are"<<endl;
    for(int i=0;i<span_tree.size();i++){
        cout<<span_tree[i][0]<<" - "<<span_tree[i][1]<<endl;
    }
    cout<<"Total min cost is: "<<cost;
}


int main(){
    find_shortest_edge();
    find_spanning_tree();
    print_result();
}