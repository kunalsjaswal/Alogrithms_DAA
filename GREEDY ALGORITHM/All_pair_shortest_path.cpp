// usually we have Floyd warshall algo for this  , but we can also use dijkstra n times to find all pair shortest path

#include<iostream>
using namespace std;

const int n=4;
int f=5643;
int A[n][n]={{0,3,f,7},
            {8,0,2,f},
            {5,f,0,1},
            {2,f,f,0}};

// int A[n][n]={ {f,50,45,10,f,f},
//                 {f,f,10,15,f,f},
//                 {f,f,f,f,30,f},
//                 {f,f,f,f,15,f},
//                 {f,20,35,f,f,f},
//                 {f,f,f,f,3,f}};

int near[n]={0};
int included[n];

void relaxation(int start,int u,int d_u){
    for(int i=0;i<n;i++){
        if(included[i]==0 && A[u][i]<f){
            int cond=d_u + A[u][i];
            if(cond<A[start][i]){
                near[i]=cond;
            }
        }
    }
}

void display(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}
int find_shortest(){
    int min=f;
    int indx=-1;
    for(int i=0;i<n;i++){
        if(near[i]<min && included[i]==0){
            min=near[i];
            indx=i;
        }
    }
    return indx;
}
void dijkstra(int start){
    for(int j=0;j<n;j++){

        int min=find_shortest();

        if(min==-1){  // no value remaining
            return;
        }
        included[min]=1;
        relaxation(start,min,near[min]);
    }
}

void update_near(int start){
    for(int i=0;i<n;i++){
        near[i]=A[start][i];
    }
}
void reset(){
    for(int i=0;i<n;i++){
        included[i]=0;
    }    
}

void update_graph(int start){
    for(int i=0;i<n;i++){
        A[start][i]=near[i];
    }
}
int main(){
    for(int i=0;i<n;i++){
        reset();
        update_near(i);

        included[i]=1;
        dijkstra(i);
        update_graph(i);
    }
    display();
    return 0;
}