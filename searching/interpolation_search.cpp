#include<iostream>
using namespace std;

int arr[]={2,5,7,9,12,16,19,21,24,45,56,66};
// int arr[]={1,3,5,7,9,11,13,15};

void interpolation(int l,int h,int key){

    if(l==h){
        cout<<"Not present"<<endl;
        return;
    }
    int m=l + ((h-l)*(key - arr[l])) / (arr[h] - arr[l]);

    if( m<l || m>h){
        cout<<"not Present"<<endl;
        return;
    }
    if(arr[m] == key){
        cout<<"Present at "<<m<<endl;
        return;
    }else if(key<arr[m]){
        h=m;
    }else{
        l=m+1;
    }
    interpolation(l,h,key);

}

int main(){
    int len=sizeof(arr)/sizeof(arr[0]);
    int key=22;
    interpolation(0,len-1,key);

}