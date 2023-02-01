#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

const int size=6;
int f=INT_MAX;
// int graph[size][size]={ {f,2,4,f,f,f},
//                         {f,f,1,7,f,f},
//                         {f,f,f,f,3,f},
//                         {f,f,f,f,f,1},
//                         {f,f,f,2,f,5},
//                         {f,f,f,f,f,f} };

int graph[size][size]={ {f,50,45,10,f,f},
                        {f,f,10,15,f,f},
                        {f,f,f,f,30,f},
                        {f,f,f,f,15,f},
                        {f,20,35,f,f,f},
                        {f,f,f,f,3,f}};
int count=1;
int included[size];
vector<vector<int>> result_set;

void starting_result(int start){
    for(int i=0;i<size;i++){
        if(i == start){
            continue;
        }
        result_set.push_back({i,graph[start][i]});
    }
}

void display(){
    for(int i=0;i<size-1;i++){
        cout<<result_set[i][0]<<" : ";
        if(result_set[i][1] == f){
            cout<<"infinity"<<endl;

        }  else{
            cout<<result_set[i][1]<<endl;

        }
    }
}

int find_min(){
    int index=-1;
    int dist=f;
    for(int i=0;i<size-1;i++){
        
        if(included[result_set[i][0]]==0){
            if(result_set[i][1] < dist){
                index=i;
                dist=result_set[i][1];
            }
        }
    }
    return index;
}

int dist(int node){
    for(int j=0;j<size;j++){
        if(result_set[j][0] == node){
            return result_set[j][1];
        }
    }
}

void relaxation(int u){
    for(int i=0;i<size-1;i++){

// all nodes which haven;t been included and also have direct connection with the u vertex 
// e.g  1-> u -> v    we have to relax v as there is no direct way from 1 to v
        int v=result_set[i][0];

            if(included[v]==0 && graph[u][v]<f){
                int path=dist(u)+graph[u][v];
                
                        if(path < dist(v)){
                            // relaxing the node 
                            for(int k=0;k<size-1;k++){
                                if(result_set[k][0] == v){
                                    result_set[k][1]=path;
                                }    
                            }
                        }
            }
    }
}

void dijkstra(int start){
    while(count!= size-1){

        // getting min distance edge from the result_set
        int min_edge=find_min();
        // display();

        // if there is directed graph and no path to reach the vertex 
        if(min_edge ==-1){  
            return;
        }
        included[result_set[min_edge][0]]=1;
        count++;
        relaxation(result_set[min_edge][0]);
    }
}
 
int main(){
    int start=4;
    
    //upadting result_set i.e calculating and storing distance from start vertex to every other vertex in graph
    starting_result(start);
    included[start]=1;

    dijkstra(start);

    display();
}