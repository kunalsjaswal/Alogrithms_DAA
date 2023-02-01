#include<iostream>
using namespace std;

const int n=5;   // total items
const int m=8;   // total capacity

int p[n+1]={0,5,10,15,8,40};
int wt[n+1]={0,3,5,2,4,7};


int T[n+1][m+1]={0};
bool result_set[n+1];

void tabular(){
    for(int i=0;i<=n;i++){
        for(int w=0;w<=m;w++){
            if(i==0 || w==0)  // if 0 profit or 0 wt
                T[i][w]=0;

            else if(wt[i]<=w) // if wt of item is less than capacity
                T[i][w]=max(T[i-1][w] , p[i]+T[i-1][w-wt[i]]);

            else              // if wt of items is more than just enter prev data
                T[i][w]=T[i-1][w];

            cout<<T[i][w]<<" ";
        }
        cout<<endl;
    }
}

bool do_not_matches(int p,int i){
    for(int w=0;w<=m;w++){
        if(T[i][w]==p){
            return 0;
        }
    }
    return 1;
}
void solve_dp(){
    int max_profit=T[n][m];
    int i=n;
    while(max_profit!=0){
        if(do_not_matches(max_profit,i-1)){
            result_set[i]=1;
            max_profit-=p[i];
            cout<<"Item "<<i<<" is included\n";
            i--;
        }
        else {
            result_set[i]=0;
            cout<<"Item "<<i<<" is not included\n";
            i--;
        }
    }
    while(i!=0){
        cout<<"Item "<<i<<" not included\n";
        result_set[i]=0;
        i--;
    }

    cout<<"{ ";
    for(int k=1;k<=n;k++)
        cout<<result_set[k]<<" ";
    cout<<"}"<<endl;
    
}

int main(){
    tabular();
    cout<<"using above table we will make decisions \n";
    solve_dp();
}