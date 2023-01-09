#include<iostream>
using namespace std;

const int size=9;
int arr[]={7,24,18,52,36,54,11,23};

class node{
public:
    int data;
    node *next;
};

node* hash_table[size];


void probing(int key,int val,node* n){
    node* temp=hash_table[key];

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

}

void chaining(){
    for(int val: arr){
        int key= val%size;
        node *n=new node;
        n->data=val;
        n->next=NULL;
        
        if(hash_table[key] == NULL){
            hash_table[key]=n;
        }else{
            probing(key,val,n);
        }
    }
}

void display(){
    int index=0;
    for(auto nodes:hash_table){
        cout<<index<<" | ";
        if(nodes == NULL){
            cout<<"-1"<<endl;
        }else{
            while(nodes!=NULL){
                cout<<nodes->data<<"->";
                nodes=nodes->next;
            }
            cout<<"->X"<<endl;
        }

        index++;
    }
    cout<<"~hash table"<<endl;
}
int main(){
    system("cls");
    // display();
    chaining();
    display();
}