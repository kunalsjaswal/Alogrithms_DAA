#include<iostream>
#include<list>
using namespace std;

const int size=4;
int heap_size=size;
int files[size+1]={0,5,2,7,4}; // 0 is not included. it is just to start with 1
int min_heap[size+1];
int cost=0;

void check_child(int root){
    // left child= ith * 2

    int l=root*2;
    int r=l+1;

    // if there is no child return.
    if(l>heap_size){
        return;
    }else if(l==heap_size){ // only left child is present
        if(files[root] > files[l]){
            //swapping
            files[root]+=files[l];
            files[l]=files[root]-files[l];
            files[root]-=files[l];
        }
        return;
    }else{
        // select shortest among the 2 children
        int shortest= files[l]<=files[r]?l:r;

        if(files[root] > files[shortest]){
            //swapping
            files[root]+=files[shortest];
            files[shortest]=files[root]-files[shortest];
            files[root]-=files[shortest];
            check_child(shortest);
        }

    }

}
void heapify(){
    for(int i=size;i>0;i--){
        // checking children. if present then compare and swap shortest one recursively
        check_child(i);
    }
}

int dlt_from_heap(){
    // swapping 1st element with last
    files[1]+=files[heap_size];
    files[heap_size]=files[1]-files[heap_size];
    files[1]-=files[heap_size]; 

    //decreasing heap size
    --heap_size;

    // fixing heap `always the root will be wrong
    check_child(1);
    return files[heap_size+1];
}

void bottom_up(int child){
    //checking the parent of last added elem.. 
    // if parent is greater replace recursively

    int parent=child/2;
    if(files[child] < files[parent]){
        files[parent]+=files[child];
        files[child]=files[parent]-files[child];
        files[parent]-=files[child]; 

        bottom_up(parent);
    }
    return;
}
void insert_to_heap(int sum){
    //1st increasing size
    //2nd adding sum into size index
    //3rd fixing heap using bottom-up

    ++heap_size;
    files[heap_size]=sum;
    bottom_up(heap_size);
}

void optimal_merge(){
    while(heap_size!=1){
        int ele1=dlt_from_heap();
        int ele2=dlt_from_heap();

        int sum=ele1+ele2;
        cost+=sum;
        cout<<"merging file with size "<<ele1<<" and "<<ele2<<" with cost= "<<sum<<endl;
        if (heap_size==1)
        {
            files[2]=sum;
            break;
        }
        
        insert_to_heap(sum);
    }

    // after only one element is left in heap
    cout<<"merging file with size "<<files[1]<<" and "<<files[2]<<" with cost= "<<files[2]+files[1]<<endl;
    cost+=files[2]+files[1];

}

int main(){
    heapify();
    system("cls");
    cout<<"## STEPS ##"<<endl;
    optimal_merge();
    cout<<"## STEPS ##"<<endl;

    cout<<"Total cost in merging "<<size<<" files is: "<<cost;
}