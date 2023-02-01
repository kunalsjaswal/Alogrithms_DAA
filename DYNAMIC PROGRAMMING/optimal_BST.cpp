#include<iostream>
using namespace std;

const int n=4;
int keys[n]={10,20,30,40};
int freq[n+1]={0,4,2,6,3};

int C[n+1][n+1];

class bst{
    public:
    bst* left;
    bst* right;
    int data;

    bst(int val){
        left=right=NULL;
        data=val;
    }
};

int w(int i,int j){
    if(i>j){
        return 0;
    }    
    return freq[i]+w(++i,j);
}
int find_min(int i,int j){
    // formula = C[i,j]=min{C[i,k-1] + C[k,j]}
    int indx=1;
    int min=1723;
    for(int k=i+1;k<=j;k++){
        if(C[i][k-1] + C[k][j] < min){
            indx=k;
            min=C[i][k-1] + C[k][j];
        }
    }

    C[j][i]=indx;
    return min+w(i+1,j);

}
void tabular(){

    // condition 1.  i==j = 0
    for(int i=0;i<=n;i++){
        C[i][i]=0;
    }

    // condition 2.  i-j=1
    for(int l=1;l<=n;l++){

        for(int i=0;i<=n-l;i++){
            C[i][i+l]=find_min(i,i+l);
        }
    }
} 

bst* apply_dp(int i,int n){
    int start=C[n][i];
    if(start==0){
        return NULL;
    }
    bst *root=new bst(keys[start-1]);
    root->left=apply_dp(i,start-1);
    root->right=apply_dp(start,n);
    return root;
}

void postorder(bst *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    tabular();

    bst *optimal_bst=apply_dp(0,n);
    // now just traverse above tree 
    postorder(optimal_bst);

    
}