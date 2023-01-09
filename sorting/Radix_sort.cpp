#include<iostream>
#include<list>
#include<math.h>
using namespace std;

int arr[]={345,654,924,123,567,472,555,808,911};

int len=sizeof(arr)/sizeof(arr[0]);

void display(){
    for(int ele: arr){
        cout<<ele<<"  ";
    }
    cout<<endl;
}
int largest(){
    int larg=arr[0];

    for(int ele: arr){
        if(ele>larg){
            larg=ele;
        }
    }
    return larg;

}

void radixSort(int itr,int end){

    while(itr!=end){
        list<int> radix[10];
        // from original array to list
        for(int ele:arr){
            int temp= ele/pow(10,itr);
            int index=temp%10;
            radix[index].push_back(ele);
        }


        // from list to array
        int j=0;
        for(int i=0;i<10;i++){
            for(int ele: radix[i]){
                    arr[j]=ele;
                    j++;
            }
        }

        cout<<"Pass "<<itr+1<<": ";
        display();
        itr++;
        
    }
}



int main(){
    cout<<"Array: ";
    display();
    cout<<endl;
    int large=largest();
    int end=0;

    while(large!=0){
        large/=10;
        end++;
    }

    radixSort(0,end);

    cout<<"\nRadix Sort: ";
    display();
}