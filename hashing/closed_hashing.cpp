/*
we gonna have a normal probing inserting function which will check the index using (k % m)
if vacant, fill the index else check next index and so on.
*/ 

#include<iostream>
using namespace std;

const int m=10;
int hashTB[m];

int arr[]={72,27, 36, 24, 63, 81,101,89,19,109,10};


void probing(int key,int val){
    // checking next vacant index to fill out the element in hash table

    // checking from key to last index i.e (key to m)

    for(int i=key+1;i<m;i++){
        if(hashTB[i] == -1){
            hashTB[i]=val;
            cout<<"key= "<<i<<", value= "<<val<<endl;
            return;
        }
    }

    // checking from starting index=0 to the prev index of key i.e (0 - key-1)
    for(int i=0;i<key;i++){
         if(hashTB[i] == -1){
            hashTB[i]=val;
            cout<<"key= "<<i<<", value= "<<val<<endl;
            return;
        }
    }

    cout<<"error. cannot insert value "<<val<<", hash table if full.\n";

}
void insert_into_table(){
    // traversing all elements of array input to insert it into hash table
    for(int ele:arr){

        int key= ele%m;
        if(hashTB[key] == -1){
            hashTB[key]=ele;
            cout<<"key= "<<key<<", value= "<<ele<<endl;
        }else{
            probing(key,ele);
        }
    }
}

void display(){
    cout<<"key | value"<<endl;
    for(int i=0;i<m;i++){
        cout<<" "<<i<<"  | "<<hashTB[i]<<endl;
    }
    cout<<"~hash table\n";
}
int main(){
    for(int i=0;i<m;i++)
        hashTB[i]=-1;

    system("cls");
    display();

    cout<<"INSERTING INTO HASH TABLE\n";
    insert_into_table();
    display();
    
}
