#include<iostream>
using namespace std;
int arr[]={5,8,12,98,54,24,13,1,0};
int size=sizeof(arr)/sizeof(arr[0]);

void display(){
    for(int ele: arr){
        cout<<ele<<"  ";
    }
    cout<<endl;
}

void swapping(int i,int j){
    arr[i]+=arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]-=arr[j];
}

int linear_search(int start){
    int smallest=start;

    for(int j=start+1;j<size;j++){
        if(arr[smallest] > arr[j]){
            smallest=j;
        }
    }

    return smallest;
}

void selection(){
    for(int i=0;i<size-1;i++){
        int smallest=linear_search(i);
        if(i!=smallest){
            swapping(i,smallest);
        }

        cout<<"PASS "<<i+1<<", Pos: "<<smallest<<": ";
        display();
    }

}


int main(){
    cout<<"Array: ";
    display();
    cout<<endl;
    selection();
}