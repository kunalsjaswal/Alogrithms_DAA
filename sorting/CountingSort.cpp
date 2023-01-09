#include<iostream>
using namespace std;

int arr[]={4,1,5,2,3,8,7,6,5,9,8,1,3,2,4,5,5,7,1,8,9,7};
// range 0-9
int count[10]={0};


int main(){
    cout<<"Array: ";
    
    for(int val: arr){
        cout<<val<<" ";
        count[val]++;
    }

    cout<<endl;
    cout<<"count sort: ";
    for(int i=0;i<10;i++){
        for(int j=0;j<count[i];j++){
            cout<<i<<" ";
        }
    }
}