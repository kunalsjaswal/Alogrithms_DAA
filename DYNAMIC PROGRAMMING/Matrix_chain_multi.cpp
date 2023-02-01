#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


void apply_dp(vector<int> d,int n){


//1.  building table 
    int m[n+1][n+1];

    for(int i=1;i<=n;i++){   // i = num of matrix to multiply (eg. i=1 == {A1, A2, A3, ..}  | i=2== {A1xA2, A2xA3, A3xA4, ..})
        
        if(i!=1){  // using formula for multiply 2 or more matrices
            
            for(int j=1;j<=n-i+1; j++){  // j = starting of matrix (eg. m[j][end]= min{ m[j][k] + m[k+1][end] + (d[j-1]*d[k]*d[end]) } )
                int end=j+i-1;
                m[j][end]=INT_MAX;

                for(int k=j; k<end; k++){  // k is the middle matrix (eg. for m[1,3] , when k=1 == m[1,1]+ m[2,3])
                    int temp_min=m[j][k] + m[k+1][end] + (d[j-1] * d[k] * d[end]);
                    
                    if(temp_min < m[j][end]){
                        m[j][end]=temp_min;
                        m[end][j]= k;
                    }
                }
            }
        }else{
            // multiplying only 1 matrix 
            for(int z=1;z<=n;z++){
                m[z][z]= 0;
            }
        }
    }


//2. applying dp - printing val only for 4 matrix
    cout<<"min no. of multiplication required = "<<m[1][n]<<endl<<"sequence = \n";
    vector<string> res;

    int start=1;
    int line=m[n][1];
    int ends=n;

    int count=0;
    while(count != n/2){
        cout<<"(";
        for(int i=start;i<=line;i++){
            cout<<"A"<<i<<" ";
        }
        cout<<")(";
        for(int i=line+1;i<=ends;i++){
            cout<<"A"<<i<<" ";
        }
        cout<<")"<<endl;
        
        if(line-start > ends-line){  // right sub part
            ends=line;
            line=m[line][1];
        }else if(line-start < ends-line){ 
            start=line+1;
            line=m[line][1];
        }else{
            break;
        }
        count++;

    }

}


int main(){

    int n;
    cout<<"enter total matrix to multiply: ";
    cin>>n;

    vector<int> d;

    cout<<"Enter dimensions for matrices: (eg. [2 3 4] = 2*3 and 3*4)\n";
    for(int i=0;i<=n;i++){
        int temp;
        cin>>temp;
        d.push_back(temp);
    }    

    apply_dp(d,n);
}