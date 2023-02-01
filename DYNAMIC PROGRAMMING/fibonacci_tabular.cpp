#include<iostream>
#include<vector>
using namespace std;

vector<int> table;

int dp_tabular(int n){
    if(n<=1) return n;

    table.push_back(0);
    table.push_back(1);
    for(int i=2;i<=n;i++){
        table.push_back(table[i-1]+table[i-2]);
    }
    return table[n];
}
void display(int n){
    for(int i=0;i<=n;i++){
        cout<<table[i]<<" ";
    }
}

int main(){
    int n=10;
    cout<<"fib("<<n<<") = "<<dp_tabular(n)<<endl;
    cout<<"fibo series till fib("<<n<<"): ";
    display(n);
}