#include<iostream>
using namespace std;

const int n=4;
int coins[n]={2,5,6,9};
const int sum=16;

int A[n][sum+1];

void tabular(){
    for(int i=0;i<n;i++){
        for(int w=0;w<=sum;w++){

            if(i!=0){
                if(w==0) A[i][w]=0;
                else if(w%coins[i] == 0) A[i][w]=w/coins[i]; 
                else if(w<coins[i]) A[i][w]=A[i-1][w];
                else {
                    if(A[i-1][w]!=0 && A[i][w-coins[i]]==0) A[i][w]=A[i-1][w];
                    else if(A[i-1][w]==0 && A[i][w-coins[i]]!=0) A[i][w]=1+A[i][w-coins[i]];
                    else A[i][w]= min(A[i-1][w],1+A[i][w-coins[i]]); 
                }
                
            }else{
                if(w==0) A[i][w]=0;
                else if(w%coins[i] == 0) A[i][w]=w/coins[i];
                else A[i][w]=0;
            }
            cout<<A[i][w]<<" ";
        }
        cout<<endl;
    }
}

void bottom_up_dp(){
    int temp=sum;
    int i=n-1;
    int w=sum;
    while(w!=0){
        if(A[i-1][w] != A[i][w]){
            cout<<coins[i]<<" ";
            w-=coins[i];
            continue;
        }
        i--;
    }


}

int main(){
    tabular();
    if(A[n-1][sum]){
        cout<<"sum="<<sum<<endl<<"coins needed="<<A[n-1][sum]<<endl<<"coin type={ ";
        bottom_up_dp();   
        cout<<"}\n";

    }else{
        cout<<"solution does not exist.\n";
    }
    return 0;
}