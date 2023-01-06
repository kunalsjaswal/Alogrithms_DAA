#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int edges[3][9]{
    {1,1,2,2,3,4,4,5,5},
    {2,6,3,7,4,5,7,6,7},
    {25,5,12,10,8,16,14,20,18}
};
const int size=8;
int set[size]={0,-1,-1,-1,-1,-1,-1,-1};
int included[size]={0};
vector<vector<int>> result;
int min_cost=0;


int find_min_edge(){
    int ind=0;
    int value=INT_MAX;

    for(int i=0;i<9;i++){
        if(included[i]==0){
            if(edges[2][i]<value){
                ind=i;
                value=edges[2][i];
            }
        }
    }
    return ind;
}

int find_parent(int x){
    while(set[x]>0){
        x=set[x];
    }
    return x;
}

void set_union(int x,int y){
    if(set[x]<set[y]){
        set[x]=set[x]+set[y];
        set[y]=x;
    }else{
        set[y]=set[x]+set[y];
        set[x]=y;
    }
}

void kruskal(){

    while(result.size()!=6){
        int min_index=find_min_edge();
        
        int edge1=edges[0][min_index];
        int edge2=edges[1][min_index];

        int p1=find_parent(edge1);
        int p2=find_parent(edge2);


        if(p1!=p2 || (p1<0 && p2<0) ){
            // no cycle condition
            result.push_back({edge1,edge2});
            included[min_index]=1;
            set_union(p1,p2);
            min_cost+=edges[2][min_index];
        }else{
            // cycle is present
            included[min_index]=1;
        }


    }
}

void display(){
    for(int i=0;i<result.size();i++){
            cout<<result[i][0]<<" - "<<result[i][1]<<endl;;
    }

    for(int i=0;i<size;i++){
        cout<<set[i]<<" ";
    }
    cout<<endl<<"min cost: "<<min_cost;
}

int main(){
    kruskal();
    display();
}