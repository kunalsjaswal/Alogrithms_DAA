#include<iostream>
using namespace std;

// Given


const int size=5;

// starting from 1 index 
bool G[size+1][size+1]={{0,0,0,0,0,0}, 
                        {0,0,1,1,0,1}, // 1
                        {0,1,0,1,1,1}, // 2
                        {0,1,1,0,1,0}, // 3
                        {0,0,1,1,0,1}, // 4
                        {0,1,1,0,1,0}};// 5

// Solution

// data structures 
int res[size+1];
int soln=0;
int start_vertex=5;

// functions 
bool no_duplicate(int end,int val){
    for(int i=1; i<end; i++){
        if(res[i] == val) return 0;
    }
    return 1;
}
bool edge_present(int f,int s,int v){
    bool conn;
    conn=G[f][s]==1?1:0;

    if(v==size && conn){
        conn=G[start_vertex][s]==1?1:0;
    }
    return conn;
}

void solve(int v){
    
    if(v == size+1){
        ++soln;
        if(soln == 1) cout<<"Yes hamiltonion cycle exist.\n";

        for(int ele=1; ele<=size; ele++) cout<<res[ele]<<" ";
        cout<<start_vertex<<endl;
        return;
    }
    for(int i=1; i<=size; i++){
        if(no_duplicate(v,i)){
            if(edge_present(res[v-1],i,v) ){
                res[v]= i;
                solve(++v);
                --v;
                res[v]=0;
            }
        }
    }

}

int main(){
    res[1]=start_vertex;
    solve(2);
    cout<<soln<<" Solutions exist.\n";
    return 0;
}

/*


*/