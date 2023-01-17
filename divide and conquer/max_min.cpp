// Finding maximum and minimum of a sequence of numbers
// now we can do it using linear search which will take O(n)
// but using divide and conquer there will be O( n) with less comparisons

#include<iostream>
using namespace std;

int arr[]={50,12,341,23,140,43,1,23,54,34};
int len=sizeof(arr)/sizeof(arr[0]);

void find_min_max(int x,int y,int *max,int *min){
    bool flag=0;
    int MAX,MIN;
    if(y-x<=0){
        flag=1;
        if(arr[x]>arr[y]){
            MAX=arr[x];
            MIN=arr[y];
        }else{
            MAX=arr[y];
            MIN=arr[x];
        }
    }else{
        find_min_max(x,((x+y)/2),max,min);
        find_min_max(((x+y)/2)+1,y,max,min);
    }


    if(flag){
    if(MAX>*max) {
        *max=MAX;
    }
    if(MIN<*min){
        *min=MIN;
    }}
}

int main(){

    int max=-1;
    int min=1000;
    
    find_min_max(0,len-1,&max,&min);

    cout<<"max: "<<max<<"\nmin: "<<min;
}