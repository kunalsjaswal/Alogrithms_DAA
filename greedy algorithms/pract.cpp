#include<iostream>
#include<vector>
using namespace std;

void change(int arr[]){
    arr[2]=10;
}
int main(){

    int i;
    int arr[5]={1,2,3,4,5};
    change(arr);
    for(i=0;i<5;i++){
        cout<<arr[i]<< " ";
    }

    vector<int> ivec={1,2,3,4,5};

    cout<<"hello";
    
}