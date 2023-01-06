#include<iostream>
#include<math.h>
using namespace std;

int arr[]={2,5,7,9,12,16,19,21,24,45,56,66};

void jump_search(int l,int k,int key,int len){

    if(key == arr[k]){
        cout<<"present at "<<k<<endl;
        return;
    }else if(key > arr[k]){
        if(k + sqrt(len) > len){
            jump_search(k,len-1,key,len);
        }else{
            jump_search(k,k+sqrt(len),key,len);
        }
        return;
    }else{
        for(int i=l;i<=k;i++){
            if(arr[i] == key){
                cout<<"present at "<<i<<endl;
                return;
            }
        }
        cout<<"Not present."<<endl;
        return;
    }
}

int main(){
    int len=sizeof(arr)/sizeof(arr[0]);
    int key=66;

    int k=sqrt(len);
   
    if(key > arr[len-1] || key< arr[0]){
        cout<<"Not present."<<endl;
    }else{
        jump_search(0,k,key,len);
    }
}