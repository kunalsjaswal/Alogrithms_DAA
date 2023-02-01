#include<iostream>
#include<vector>
using namespace std;

vector<int> memo;
int count=0;
void fillmemo(int n){ for(int i=0;i<=n;i++) memo.push_back(-1);}

int dp_memoization(int n){
    int r;
    if(memo[n]!=-1){
        r=memo[n];

    }else{
        if(n<=1){
            r=n;
            memo[n]=r;
            count++;
        }else{
            count++;
            r=dp_memoization(n-1)+dp_memoization(n-2);
            memo[n]=r;

        }
    }
    return r;
}

void display(int n){
    for(int i=0;i<=n;i++){
        cout<<memo[i]<<" ";
    }
}

int main(){
    int n=15;
    fillmemo(n);
    cout<<"fib("<<n<<") = "<<dp_memoization(n)<<endl;
    cout<<"fibo series till fib("<<n<<"): ";
    display(n);
    cout<<endl<<"total times fib() function call: "<<count;
}