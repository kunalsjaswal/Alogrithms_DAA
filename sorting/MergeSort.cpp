#include<iostream>
using namespace std;
int arr[]={5,1,8,12,98,54,324,123,1,0};
int len=sizeof(arr)/sizeof(arr[0]);


void display(){
    for(int ele: arr){
        cout<<ele<<"  ";
    }
    cout<<endl;
}


void merge(int beg,int mid,int end){
    int i=beg, j=mid+1;
    int index=beg;
    int temp[len];

    cout<<"Merging these 2 arrays: ";
    for(int i=beg;i<=end;i++){
        cout<<arr[i]<<" ";
        if(i == mid){
            cout<<" | ";
        }
    }
    cout<<"\n";

    while( i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[index]= arr[i];
            i++;
        }else{
            temp[index]=arr[j];
            j++;
        }
        index++;
    }


    if(i>mid){
        while(j<=end){
            temp[index]=arr[j];
            j++;
            index++;
        }
    }else{
        while(i<=mid){
            temp[index]=arr[i];
            i++;
            index++;
        }
    }

    for(int i=beg;i<index;i++){
        arr[i]=temp[i];
    

    cout<<"After merging: ";
     for(int i=beg;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }
}

void merge_sort(int beg,int end){

    if(beg<end){
        int mid=(beg+end)/2;
        merge_sort(beg,mid);
        merge_sort(mid+1,end);
        merge(beg,mid,end);
    }
}

int main(){
    system("cls");
    cout<<"Array: ";
    display();
    cout<<endl;

    cout<<"### STEPS ###"<<endl;
    merge_sort(0,len-1);
    cout<<"### STEPS ###"<<endl;

    cout<<"\nMerge Sort: ";
    display();
}