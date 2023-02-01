#include<iostream>
#include<queue>
#include<list>
using namespace std;

const int size=5;
list<int> graph[5];
int indegree[5];

queue<int> Q;
void display_graph(){
    for(int i=0;i<size;i++){
        cout<<i<<"-> ";
        for(int ele: graph[i]){
            cout<<ele<<"->";
        }
        cout<<"X"<<endl;
    }
}
    
void calculate_in_degree(){
    for(int i=0;i<size;i++){
        for(int ele: graph[i]){
            indegree[ele]++;
        }
    }

    // starting phase - pushing elements having indegree 0
    for(int i=0;i<size;i++){
        if(indegree[i]==0){
            Q.push(i);
        }
    }
} 
void tp_sort(){

    if(Q.empty()){
        return;
    }

    int u=Q.front();
    Q.pop();
    cout<<u<<" ";

    for(auto ele: graph[u]){
        indegree[ele]--;
        if(indegree[ele]==0){
            Q.push(ele);
        }
    }
    tp_sort();
}

void show_ind(){
    for(int i:indegree){
        cout<<i<<" ";
    }
}

int main(){
    graph[0].push_back(3);

    graph[1].push_back(0);
    graph[1].push_back(2);

    graph[3].push_back(2);
    graph[4].push_back(1);

    display_graph();
    calculate_in_degree();

    tp_sort();

}