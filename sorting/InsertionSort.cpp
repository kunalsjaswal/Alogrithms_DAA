#include<iostream>
using namespace std;
// O(n^2), good for small set of data

int arr[]={5,1,8,12,98,54,324,123,1,0};
int len=sizeof(arr)/sizeof(arr[0]);

void display(int line){
    for(int i=0;i<len;i++){
        if(line+1==i){
            cout<<arr[i]<< " |  ";
        }else{
            cout<<arr[i]<< "  ";
        }
    }
    cout<<endl;
}
void find_pos(int i){
    if(i==-1){
        return;
    }
    if(arr[i+1]<arr[i]){
        arr[i]+=arr[i+1];
        arr[i+1]=arr[i]-arr[i+1];
        arr[i]-=arr[i+1];
        find_pos(i-1);
    }
    return;
}

void insertion(){

    for(int i=0;i<len-1;i++){
        cout<<"PASS "<<i+1<<": ";
            find_pos(i);
            display(i);
    }

}
int main(){
    cout<<"Array: ";
    display(-2);
    cout<<"\tsorted  |  unsorted\n"<<endl;
    insertion();
}