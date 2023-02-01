#include<iostream>
using namespace std;

void lcs_dp(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    // starting index =1
    int table[m+1][n+1];

    // initializing 0th index of table to 0
    // so if you want to retreive char from string s1||s2 then just sub 1
    for(int i=0;i<=m;i++){
        table[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        table[0][i]=0;
    }

    // inserting data into table- top-down approch 
    for(int i=0;i<=n;i++) cout<<"0 ";
    cout<<endl;
    for(int i=1; i<=m; i++){
        cout<<0<<" ";
        for(int j=1; j<=n; j++){
            
            if(s1[i-1] == s2[j-1]){
                table[i][j]=1+table[i-1][j-1];
            }else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
            cout<<table[i][j]<<" ";

        }
        cout<<endl;
    }

    // applying bottoms-up decision approach
    cout<<"\nLCS length= "<<table[m][n]<<"\nLCS= ";
    int i=m,j=n;
    string lcs="";
    while(i!=0 && j!=0 && table[i][j]!=0){
        if(table[i][j-1] != table[i-1][j]){

            if(table[i][j] == table[i][j-1]) j--;
            else i--;
        }else{
            if(table[i][j] == table[i][j-1]) j--;
            else{
                lcs+=s2[j-1];
                i--,j--;
            }
        }
    }

    // printing lcs 
    for(int c=table[m][n]-1; c>=0; c--){
        cout<<lcs[c];
    }
    cout<<endl;
}

int main(){
    string s1,s2;
    cout<<"enter string 1: ";
    cin>>s1;
    cout<<"enter string 2: ";
    cin>>s2;

    lcs_dp(s1,s2);
}