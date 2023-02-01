#include<iostream>
#include<stack>
using namespace std;


int Graph[7][7]={{0,1,0,1,0,0,1},
                {1,0,0,0,1,1,0},
                {0,0,0,0,0,1,0},
                {1,0,0,0,0,1,0},
                {0,1,0,0,0,0,1},
                {0,1,1,1,0,0,0},
                {1,0,0,0,1,0,0}};

int visited[7];
stack<int> st;

void dfs(int start){
    

    for(int i=0;i<7;i++){
        if(Graph[start][i]==1 && visited[i]==0){
            visited[i]=1;
            st.push(i);
            cout<<i<<" ";
            dfs(i);
            return;
        }
    }
    if(st.empty()){
        return;
    }

    int u=st.top();
    st.pop();        
    dfs(u);
}

int main(){
    int start=4;

    st.push(start);
    visited[start]=1;
    cout<<"DFS: "<<start<<" ";
    dfs(start);
}