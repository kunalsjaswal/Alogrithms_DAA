// it is to find path matrix for a given graph with 
// given: adj matrix/ adj list ,     
#include<iostream>
using namespace std;

const int size=4;
bool A[size][size]= {{0,0,0,1},
                    {1,0,1,1},
                    {1,0,0,1},
                    {0,0,1,0}};

void warshall(){
    for(int k=0;k<size;k++){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                A[i][j]=A[i][j] || (A[i][k] && A[k][j]);
            }
        }
    }
}

void display(){
    for(int i=0;i<size;i++){
        for(int val: A[i]){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cout<<"adjacency Matrix"<<endl;
    display();

    warshall();

    cout<<endl<<"path Matrix"<<endl;
    display();
}