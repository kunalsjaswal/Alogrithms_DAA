// for kruskal algo we req 2 operations to detect cycle:
// 1. union ,  2. find() ~parent

#include<iostream>
#include<vector>
using namespace std;


void insert_set(vector<int> &S,vector<int> A){
    
    // for parent 
    int parent=A[0];
    S[parent]=-A.size();
    for(int i=1;i<A.size();i++){
        S[A[i]]=parent;
    }
}

void set_unions(vector<int> &S,vector<int> A,vector<int> B){
    if(S[A[0]]<S[B[0]]){
        // A has mode children
        S[A[0]]= S[A[0]]+S[B[0]];
        S[B[0]]= A[0];
    }else{
        S[B[0]]= S[A[0]]+S[B[0]];
        S[A[0]]= B[0];
    }
}

void find(vector<int> S,int x){
    while(S[x]>0){
        x=S[x];
    }
    cout<<x<<" is the parent"<<endl;
}

void display(vector<int> S){
    for(int i=0;i<S.size();i++){
        cout<<" | "<<S[i];
    }
    cout<<" |"<<endl;
}



int main(){
    vector<int> U{1,2,3,4,5,6,7,8,9,10};

    // initially every element is subset of its own set
    vector<int> S{0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    
    vector<int> A{2,8,3};
    vector<int> B{4,5,7,9};

    display(S);
    insert_set(S,A);
    insert_set(S,B);
    display(S);
    set_unions(S,A,B);
    display(S);
    find(S,7);

}