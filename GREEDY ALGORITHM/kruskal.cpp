#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int edges[3][9]{{1,1,2,2,3,4,4,5,5},         //1st vertex
                {2,6,3,7,4,5,7,6,7},         // 2nd vertex
                {25,5,12,10,8,16,14,20,18}}; // cost

const int vertex=8;
int set[vertex];
int included[vertex];
int cost=0;
vector<vector<int>> span_tree;

void set_init(){
    for(int i=0;i<vertex;i++){
        set[i]=-1;
    }
}

int find_min_edge(){
    int index=0;
    for(int i=0;i<9;i++){
        if(included[i]==0){
            if(edges[2][i]<edges[2][index]){
                index=i;
            }
        }
    }
    return index;
}

int find_parent(int x){
    while(set[x]>0){
        x=set[x];
    }
    return x;
}

void union_set(int x,int y){
    if(set[x]<set[y]){  // x vertex has more children or elements in its set than y vertex. then it will become the parent of union set
        set[x]+=set[y];
        set[y]=x;       // y will become child of x
    }else{
        set[y]+=set[x];
        set[x]=y;
    }
}

void kruskal_algo(){
    while(span_tree.size()!=6){

        int min_edge=find_min_edge();

        int s=edges[0][min_edge];
        int e=edges[1][min_edge];

        int p1=find_parent(s);
        int p2=find_parent(e);

        if(p1!=p2) // parents are not same i.e disjoint set
        {
            included[min_edge]=1;
            cost+=edges[2][min_edge];
            span_tree.push_back({s,e});
            union_set(p1,p2);
        }else{
            // including the edge for future references such that we do not choose this again as it will create a cycle
            included[min_edge]=1;
        }
    }
}

void display(){
    for(int i=0;i<vertex-2;i++){
        cout<<span_tree[i][0]<<" - "<<span_tree[i][1]<<endl;
    }
    cout<<"min cost = "<<cost;
}
int main(){
    set_init(); // initalizing every vertex as its own parent at starting
    kruskal_algo();

    display();
}