#include<iostream>
using namespace std;

const int n=5;
int A[n]={2,3,7,8,10};
const int sum=15;

bool R[n][sum+1];

void create_table(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){

            if(i!=0){
                if(j<A[i]) R[i][j]=R[i-1][j];
                else if(A[i]==j || j==0 || R[i-1][j]==1) R[i][j]=1;
                else  R[i][j]=R[i-1][j-A[i]];

            }else{
                // for the 1st row
                if(A[i]==j || j==0) R[i][j]=1;
                else R[i][j]=0;
            }

            cout<<R[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dp_subset(){
    int j=sum;
    for(int i=n-1;i>=0;i--){
        if(j==0) return;

        if(R[i-1][j] == 0 && R[i][j]==1)  {
            cout<<A[i]<<" ";
            j-=A[i];
        }
        
    }
}

int main(){

    create_table();
    bool result=R[n-1][sum];

    if(result){
        cout<<"Subset present: { ";
        dp_subset();
        cout<<"} = "<<sum<<"\n";
    }else{
        cout<<"Subset not present\n";
    }
}