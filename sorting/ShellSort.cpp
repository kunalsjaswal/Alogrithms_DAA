#include<iostream>
using namespace std;

// advancement of insertion sort
int arr[]={63,19,7,90,81,36,54,45,72,27,22,9,41,59,33};
int len=sizeof(arr)/sizeof(arr[0]);


// manually filling gap ~ we can also choose as gap=(gap+1)/2 { where gap=size
// int gap_ar[]={0,8,5,3,1};

void display(){
    for(int ele: arr){
        cout<<ele<<"  ";
    }
    cout<<endl;
}
void insertion_sort(int i,int j,int gap){
    while(i>=0){
        if(arr[i]>arr[j]){
            // swapping if element if larger
            arr[i]+=arr[j];
            arr[j]=arr[i]-arr[j];
            arr[i]-=arr[j];
        }else{
            return;
        }
        j=i;
        i-=gap;
    }
}

void shell(int gap,int pass,int flag){
    int i=0,j=gap;
    
    while(j!=len){
        insertion_sort(i,j,gap);
        i++,j++;
    }

    if(gap>=1 && flag){
        if(gap == 1){
            flag=0;
        }
        cout<<"Pass (gap="<<gap<<")"<<pass<<": ";
        display();
        gap=(gap+1)/2;
        shell(gap,++pass,flag);
    }

    return;
}

int main(){
    cout<<"Array: ";
    display();
    cout<<endl;

    int gap=len/2;
    shell(gap,1,1);
}