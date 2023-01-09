#include<iostream>
using namespace std;
int arr[]={5,1,8,12,98,324,123,1,54};

int len=sizeof(arr)/sizeof(arr[0]);


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

int partition(int beg,int pivot){
    int index=beg-1;
    for(int i=beg;i<=pivot;i++){
        if(arr[i] <= arr[pivot]){
            index++;

            if(index<i){
                swapping(index,i);
            }
        }
    }
    for(int k=beg;k<=pivot;k++){
        if(k == index || k == index+1){
            cout<<"| ";
        }
        cout<<arr[k]<<" ";
    }
    cout<<endl;
    return index;
}
void quick(int beg,int pivot){
    
    if(beg<pivot){
        cout<<" pivot element= "<<arr[pivot]<<endl<<"array: ";
        int indx=partition(beg,pivot);

        cout<<"\nleft sub-array:";
        quick(beg,indx-1);

        cout<<"\nright sub-array:";
        quick(indx+1,pivot);
    }

}


int main(){
    system("cls");
    cout<<"Array: ";
    display();
    
    // choosing last element as pivot
    int pivot= len-1;
    quick(0,pivot);

    cout<<"\nquick sort: ";
    display();

}