#include<iostream>
using namespace std;

// O(n^2)
// using flag. if array is already sorted then we can reduce time complexity to O(n) otherwise it will b same O(n^2)

int arr[]={5,1,8,12,98,54,324,123,1,0};
void display(){
    for(int ele: arr){
        cout<<ele<< " ";
    }
    cout<<endl;
}

void swapping(int i,int j){
    arr[j]+=arr[j+1];
    arr[j+1]=arr[j]-arr[j+1];
    arr[j]-=arr[j+1];
}

void bubble(){
    int size=sizeof(arr)/sizeof(arr[0]);
    int flag=0;
    for(int i=0 ; i< size-1 ; i++){
        for(int j=0;j<(size-1)-i ; j++){
            if(arr[j] > arr[j+1]){
                flag=1;
                swapping(i,j);
            }
        }
        if(flag==0){
            cout<<"Already sorted array: ";
            display();
            return;
        }
        cout<<"PASS "<<i+1<<": ";
        display();
    }
}


int main(){
    cout<<"Array: ";
    display();
    cout<<endl;
    bubble();
}