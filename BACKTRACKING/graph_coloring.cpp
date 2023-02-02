#include<iostream>
#include<vector>
using namespace std;

// Given
const int size=4;
bool G[size][size]={{0,1,0,1},
                    {1,0,1,0},
                    {0,1,0,1},
                    {1,0,1,0}};

const int n=3;
char colors[n]={'R','B','G'};

// SOlution
vector<char> res;
void fillres(){
    for(int i=0; i<size; i++){
        res.push_back('?');
    }
}
int soln=0;

bool no_bound(int end,char color){

    // cheking color of neighbouring vertex 
    for(int i=0; i<size;i++){
        if(G[end][i]){ // neighbour elements

              if(res[i] == color) return 0;
        }
    }

    return 1;
}
void solve(int v){
    if(v == size){
        soln++;
        for(char ele: res) cout<<ele<<" ";
        cout<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(no_bound(v, colors[i])){
            res[v]=colors[i];
            solve(++v);
            --v;
            res[v]='?';
        }
    }
}

int main(){

    fillres();
    solve(0);
    cout<<soln<<" solution exist\n";
    return  0;
}