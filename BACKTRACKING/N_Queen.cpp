#include<iostream>
#include<vector>
using namespace std;

// n :- number of queens
// res :- pos array for n queens
// board :- 2d array 
// count :- total solutions exist

const int n=6;
vector<int> res;
bool board[n+1][n+1];
int count=0;


// in column_cond() :- i've traversed the res[] array till Queen n
//                     eg., if Q=3 then checking from 0 to 2. whether both the columns are same or not 
bool column_cond(int pos,int queen){
    for(int i=0;i<queen-1;i++){
        if(res[i] == pos){
            return 0;
        }
    }
    return 1;
}

//in Diagonal_cond() :- i've checked left and right diagonal corresponding to the Queen
//                      for left: difference is same
//                      for right: sum is same 

bool diagonal_cond(int pos, int queen){
    for(int i=1;i<queen;i++){
        
        for(int j=1;j<=n;j++){
            if( i-j == queen - pos|| i+j == pos+queen) // left || right diagonal
            {
                if(board[i][j] == 1){
                    return 0;
                }   
            }
        }
    }
    return 1;
}

// in print_res():- printing elements of res[] array. and also deleting last element of array for further solutions
void print_res(){
    cout<<"solution "<<count<<": ";
    for(int val: res){
        cout<<val<<" ";
    }
    cout<<endl;
}


// using recursion 
void backtracking(int Q){
    // if Q is less than given problem then placing the position 
    if(Q<=n){

        for(int Qn=1;Qn<=n;Qn++){

            if(column_cond(Qn,Q) && diagonal_cond(Qn,Q)){   // safe state conditions

                res.push_back(Qn);   // pushing into array  
                board[Q][Qn]=1;      // upadting board pos of queen
                backtracking(Q+1);   // recursive call for next queen
            }    
        }
    }

    // whenever the loop will end then it will check if the solution exist or not
    // if exist then call print_res()
    // else erase prev pos of queen and also last element from res[] array
    if(res.size()==n){
       count++;
       print_res();
       board[Q-1][res[Q-2]]=0;
       res.pop_back();
    
    }else{
       if(Q>1){
            board[Q-1][res[Q-2]]=0;
       }

        res.pop_back();
    }

}

int main(){
    system("cls");
    backtracking(1);
    cout<<n<<" queen problem contains "<<count<<" solutions";
}