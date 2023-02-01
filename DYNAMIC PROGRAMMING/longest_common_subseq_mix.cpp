#include<iostream>
using namespace std;
/*
string s1="bd";
string s2="abcd";
const int m=3;
const int n=5;


string s1="abaaba";
string s2="babbab";
const int m=7;
const int n=7;
*/

string s1="stone";
string s2="longest";
const int m=6;  // length+1
const int n=8;  // length+1

int using_recursion(int i,int j){  //O(2^n)
    if(i==s1.length() || j==s2.length())
        return 0;
    else if(s1[i] == s2[j])
        return 1 + using_recursion(i+1, j+1);
    else 
        return max( using_recursion(i+1,j),using_recursion(i,j+1) );
}



int memo[m][n];
int using_memoization(int i, int j){    // O(m x n) - recursive+memoization = top-down approch

    if(memo[i][j] != -1)
        return memo[i][j];
    else if(i==s1.length() || j==s2.length())
        memo[i][j]=0;
    else if(s1[i] == s2[j])
        memo[i][j]=1 + using_memoization(i+1, j+1);
    else 
        memo[i][j]=max( using_memoization(i+1,j),using_memoization(i,j+1) );
    
    return memo[i][j];
}

int tabular[m][n];
// starting string from 1 index 

void fill_table(){
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            if(s1[i-1] == s2[j-1]){
                tabular[i][j]= 1+ tabular[i-1][j-1];
            }else{
                tabular[i][j]= max(tabular[i-1][j] , tabular[i][j-1]);
            }
}

void using_dp_bottom_up(){
    fill_table();
    cout<<"Length of LCS: "<<tabular[m-1][n-1]<<endl;
    
    
    int i=m-1,j=n-1;
    string lcs="";
    while(1){
        if(i==0 || j==0){
            for(int c=lcs.length()-1;c>=0;c--){
                cout<<lcs[c];
            }
            cout<<endl;
            return;
        }

        if(tabular[i][j-1] != tabular[i-1][j]){
            if(tabular[i][j]==tabular[i][j-1]){
                j--;
            }else{
                i--;
            }
        }else{
            if(tabular[i][j] == tabular[i][j-1]){
                j--;
            }else{
                lcs+=s1[i-1];
                i--,j--;
            }
        }
    }

}

int main(){

    cout<<using_recursion(0,0)<<endl;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) 
            memo[i][j]=-1;

    cout<<using_memoization(0,0)<<endl;
    using_dp_bottom_up();


}