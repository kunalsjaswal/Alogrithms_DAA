#include<iostream>
using namespace std;

// O(n^2)
// Starting from 1 so leaving [0] 
const int n=8;   // n = vertex
int C[n+1][n+1]{
            {0,0,0,0,0,0,0,0,0},
            {0, 0,2,1,3,0,0,0,0},
            {0, 0,0,0,0,2,3,0,0},
            {0, 0,0,0,0,6,7,0,0},
            {0, 0,0,0,0,6,8,9,0},
            {0, 0,0,0,0,0,0,0,6},
            {0, 0,0,0,0,0,0,0,4},
            {0, 0,0,0,0,0,0,0,5},
            {0, 0,0,0,0,0,0,0,0}};

int cost[n+1];
int d[n+1];


int main(){
    // starting from 1 and ending to 8 so, cost of 8=0 
    cost[n]=0;


    // filling up the cost - vertex table. 
    for(int i=n-1;i>0;i--){
        int min=9812;

        for(int k=i;k<=n;k++){
            if( C[i][k]!=0 ){
                int dist=C[i][k]+cost[k];
                if(dist<min){
                    min=dist;
                    d[i]=k;
                }
            }
        }
        cost[i]=min;
    }

    // applying decisions (forward) to find optimal min
    int pos=1;
    cout<<"path: ";
    while(pos!=8){
        cout<<pos<<"-";
        pos=d[pos];
    }
    cout<<pos<<endl<<"min cost: "<<cost[1]<<endl;
}