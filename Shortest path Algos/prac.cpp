#include<iostream>
#include<vector>
using namespace std;


void change(vector<int> &arr){
arr[0]=5;
}

void display( vector<int> arr){
    for(int val: arr){
        cout<<val;
    }
}
int main(){
    vector<int> arr{1,2};
   
   display(arr);
    change(arr);
   display(arr);

    return 0;
}