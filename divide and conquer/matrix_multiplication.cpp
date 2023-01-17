#include<iostream>
using namespace std;

const int size=4;
int A[size][size]={{2,1,4,5},
             {5,1,2,3},
             {6,4,5,1},
             {1,7,4,3}};

int B[size][size]={{5,1,2,3},
             {2,1,4,5},
             {1,7,4,3},
             {6,4,5,1}};

int result[size][size];


void naive_method(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            result[i][j]=0;

            for(int k=0;k<size;k++){
                result[i][j]+=(A[i][k] * B[k][j]);
            }
        }
    }

}


void display(){
    for(int i=0;i<size;i++){
        for(int ele: result[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    naive_method();
    display();
    
}