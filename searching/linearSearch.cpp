#include<iostream>
using namespace std;

int main(){
    int arr[]={2,5,1,76,9,3,2,1,76,23,76};
    int num;
    bool result=0;
    cout<<"enter element to search: ";
 
        cin>>num;
        for(int ele: arr){
            if(ele == num){
                result=1;
                break;
            }
        }

        if(result){
            cout<<"present."<<endl;
        }else{
            cout<<"not present."<<endl;
        }

    
}