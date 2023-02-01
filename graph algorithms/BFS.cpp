#include<iostream>

#include<queue>
using namespace std;

const int size=7;

int Graph[size][size]={{0,1,0,1,0,0,1},
                        {1,0,0,0,1,1,0},
                        {0,0,0,0,0,1,0},
                        {1,0,0,0,0,1,0},
                        {0,1,0,0,0,0,1},
                        {0,1,1,1,0,0,0},
                        {1,0,0,0,1,0,0}};
int included[size];
queue<int> Q;



void bfs(int start){
    included[start]=1;
    int u;
    Q.push(start);
    while(!Q.empty()){
        u=Q.front();
        Q.pop();

        for(int i=0;i<size;i++){
            if(Graph[u][i]==1 && included[i]==0){
                cout<<" "<<i;
                included[i]=1;
                Q.push(i);
            }
        }
    }
}

int main(){
    int start=1;
    cout<<"BFS: "<<start;
    bfs(start);   
}
