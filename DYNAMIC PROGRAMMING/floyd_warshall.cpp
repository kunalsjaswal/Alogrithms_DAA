// All Pairs Shortest Path
// this can also be solved using greedy method i.e dijkstra algo.
// applying dijkstra for every vertex. O(n^2 * n) = O(n^3)
// using Dp, it is similar to warshall path matrix algo with O(n^3)
#include<iostream>
using namespace std;

const int v=4;
const int f=2341;
int A[v][v]={{0,3,f,7},
            {8,0,2,f},
            {5,f,0,1},
            {2,f,f,0}};

void display(){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(A[i][j]==f){
                cout<<"f"<<" ";
            }else{
                cout<<A[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){

    for(int k=0;k<v;k++)
        for(int i=0;i<v;i++)
            for(int j=0;j<v;j++)
                A[i][j]=min(A[i][j] , A[i][k]+A[k][j]);
    

    display();


}