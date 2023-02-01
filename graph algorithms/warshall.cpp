// to get path matrix of a graph
#include <iostream>
using namespace std;

const int size=6;
bool graph[size][size]{{0,1,0,0,0,0},
                        {0,0,1,0,0,0},
                        {0,0,0,0,1,0},
                        {0,1,0,0,0,0},
                        {0,0,0,1,0,1},
                        {0,0,0,0,0,0}};

void display(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cout<<"graph \n";
    display();
    for(int k=0;k<size;k++) 
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                graph[i][j]=graph[i][j] || (graph[i][k] && graph[k][j]);
    cout<<"path matrix"<<endl;
    display();
}