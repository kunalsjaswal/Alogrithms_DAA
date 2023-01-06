// divide and conquer
// array should be sorted

#include<iostream>
using namespace std;

int arr[]={2,5,7,9,12,16,19,21,24,45,56,66};

void bSearch(int l,int m,int r,int key){
    if(key == arr[m]){
        cout<<"Present at index "<<m;
        return;
    }else if(key < arr[m]){
        r=m;
        m=(l+m)/2;
    }else{
        l=m+1;
        m=(m+r)/2;
    }
    if(l >= r){
        cout<<"Not present.";
        return;
    }
    bSearch(l,m,r,key);
}

int main(){
    int len=sizeof(arr)/sizeof(arr[0]);
    int key=66;
    bSearch(0,(len/2),len,key);
}