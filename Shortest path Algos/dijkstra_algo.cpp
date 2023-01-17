// it is used to find shortest path (direct or indirect) from a particular vertice to every other vertix

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

const int size=6;
int f=INT_MAX;
// int graph[size][size]={ {f,2,4,f,f,f},
//                         {f,f,1,7,f,f},
//                         {f,f,f,f,3,f},
//                         {f,f,f,f,f,1},
//                         {f,f,f,2,f,5},
//                         {f,f,f,f,f,f} };

int graph[size][size]={ {f,50,45,10,f,f},
                        {f,f,10,15,f,f},
                        {f,f,f,f,30,f},
                        {f,f,f,f,15,f},
                        {f,20,35,f,f,f},
                        {f,f,f,f,3,f}};

vector<vector<int>> result;
int included[size]={0};
int count=1;

void starting_result(int node){
    for(int i=0;i<size;i++){
        if (i == node)
        {
            continue;
        }
        result.push_back({i,graph[node][i]});
        
    }
}

int select_least(int start){
    int min=f;
    int indx;
    for(int i=0;i<result.size();i++){
        if(included[result[i][0]]==0){
            
            if(result[i][1]<=min){
                min=result[i][1];
                indx=result[i][0];
            }
        }
    }

    if(min==f){
        return -1;
    }
    return indx;
}

int find_dist(int u){
    for(int i=0;i<result.size();i++){
        if(result[i][0] == u){
            return result[i][1];
        }
    }
}

void change_dist(int v,int val){
    for(int i=0;i<result.size();i++){
        if(result[i][0] == v){
            result[i][1]= val;
        }
    }
}

void relaxation(int u){
    
    for(int i=0;i<size;i++){
        if(graph[u][i]<f){
            int v=i;

            if(included[v]==0){
                // performing relaxtion 
                // we have to find dist from result
                int cond=find_dist(u) + graph[u][i];
                 if(cond < find_dist(v)){
                    change_dist(v,cond);

                 }
            }
        }
    }
}

void dijkstra(int start){
    while(count!=size-1){
        int min_node=select_least(start);
        included[min_node]=1;
        count++;

        // ## main . i.e if we got infinity dist than no need for relaxation.
        if(min_node!=-1){
            relaxation(min_node);
        }
    }
}

void display(int start){
    cout<<endl<<"Starting node= "<<start<<endl;
    for(int i=0;i<result.size();i++){
        cout<<"to node: "<<result[i][0]<<", with cost: ";
        if(result[i][1]!=f){
            cout<<result[i][1]<<endl;
        }else{
            cout<<"infinity"<<endl;
        }
    }
}

int main(){
    int start;
    cout<<"enter starting node(0-5): ";
    cin>>start;

    starting_result(start);
    included[start]=1;

    dijkstra(start);

    display(start);

}