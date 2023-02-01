#include<iostream>
#include<limits.h>
#include<map>
#include<vector>
using namespace std;

const int f=INT_MAX;

map<int,int> result_set;
vector<vector<int>> pairs;
/*

// graph without -ve cycle
const int size=6;
int graph[size][size]={ {0,6,4,5,f,f},
                        {f,f,f,f,-1,f},
                        {f,-2,f,f,3,f},
                        {f,f,-2,f,f,-1},
                        {f,f,f,f,f,3},
                        {f,f,f,f,f,f}};
*/

//graph with -ve cycle
const int size=4;
int graph[size][size]{  {0,4,5,f},
                        {f,f,f,7},
                        {f,-1,f,f},
                        {f,f,-10,f}};

void init_resultset(){
    for(int i=0;i<size;i++){
        result_set.insert(pair<int,int>(i,graph[0][i]));
    }
}

void calculate_pairs(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(graph[i][j]<f){
                pairs.push_back({i,j});
            }
        }
    }
}
/*

void bellman(){
    int timer=size-1;
    while(timer--){
        bool flag=0;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i!=j && graph[i][j]<f){
                    int dist=graph[i][j] + result_set[i];

                    if(dist < result_set[j]){
                        result_set[j]=dist;
                        flag=1;
                    }
                }

            }
        }
        if(!flag){
            cout<<"performed "<<size-1-timer<<" times to get the result"<<endl;
            return;
        }    
    }
    cout<<"performed "<<size-2-timer<<" times to get the result"<<endl;
   
}

*/
void bellman(){
    int timer=size-1;
    while(timer--){
        int flag=0;

        for(int i=1;i<pairs.size();i++){
            int v1=pairs[i][0];
            int v2=pairs[i][1];
            int dist=graph[v1][v2] + result_set[v1];

            if(dist < result_set[v2]){
                    result_set[v2]=dist;
                    flag=1;
            }
        }

        if(!flag){
            return;
        }
    }
}

// to check -ve cycle - we have to perform one more time. if values changes then it is present
void check_neg_cycle(){
     int flag=0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size;j++){
            if(i!=j && graph[i][j]<f){
                int dist=graph[i][j] + result_set[i];

                if(dist < result_set[j]){
                    result_set[j]=dist;
                    flag=1;
                }
            }

        }
    }
    if(!flag){
        cout<<"-ve cycle is not present"<<endl;
    }else{
        cout<<"-ve cycle is present"<<endl;
    }
}

void display(){
    for(int i=0;i<size;i++){
        cout<<"0 - "<<i<<" | "<<result_set[i]<<endl;
    }
}

int main(){
// taking 0 vertex as a starting point. can take any vertex
    init_resultset();

    calculate_pairs();
    bellman();
    display();
    check_neg_cycle();
}