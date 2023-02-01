#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

class node{
    public:
    node *left;
    node *right;
    int data;
    char symbol;

    node(char sym,int val){
        data=val;
        symbol=sym;
        left=NULL;
        right=NULL;
    }
};

string msg="KUNAL KAISE HO";

map<char,int> hash_table;
map<char,string> huffman_code;
vector<node*> content;
int cost=0;

void freq_table(){
    for(int i=0;i<msg.size();i++){
        // int index=hash_fnx((int)msg[i]);
        if(hash_table.find(msg[i]) == hash_table.end()){
            hash_table.insert(pair<char,int>(msg[i],1));
        }else{
            hash_table[msg[i]]++;
        }
    }
}
void create_vector(){
    map<char,int>::iterator it=hash_table.begin();

    while(it!=hash_table.end()){
        node *n=new node(it->first,it->second);
        content.push_back(n);
        it++;
    }
    
}

int find_min(){
    vector<node*>::iterator it=content.begin();
    int min_ind=0;
    for(int i=1;i<content.size();i++){
        if(it[i]->data<it[min_ind]->data){
            min_ind=i;
        }
    }
    return min_ind;
}
void optimal_merge(){
    while(content.size()!=1){
        int min1=find_min();
        
        int sum=content[min1]->data;
        content[min1]->data=INT_MAX;

        int min2=find_min();

        content[min1]->data=sum;
        sum+=content[min2]->data;

        cost+=sum;

        node *n=new node('@',sum);
        n->left=content[min1];
        n->right=content[min2];
        
        if(min1>min2){
            // in vector. if pos of min2 comes 1st then we will delete min1 1st. this wont change pos of min2
            content.erase(content.begin()+min1);
            content.erase(content.begin()+min2);
        }else{
            content.erase(content.begin()+min2);
            content.erase(content.begin()+min1);
        }

        content.push_back(n);
    }
}

void huffman(node *root,string code){
    if(root->left==NULL){
        huffman_code[root->symbol]=code;
        return;
    }
    huffman(root->left,code+"0");
    huffman(root->right,code+"1");
}

void display(){
    cout<<"Huffman code table"<<endl;
    map<char,string>::iterator it=huffman_code.begin();
    string coded="";
    while(it!=huffman_code.end()){
        cout<<it->first<<" | "<<it->second<<endl;
        it++;    
    }

    for(int i=0;i<msg.length();i++){
        coded+=huffman_code[msg[i]]+"-";
    }

    cout<<"\nmessage: '"<<msg<<"'\ncoded: "<<coded;




}

int main(){
    freq_table();
    create_vector();
    optimal_merge();
    huffman(content[0],"");
    display();
    return 0;
}