#include<iostream>
using namespace std;

// given 
const int n=6;
int set[n]={5,10,15,20,25,30};
int sum=60;

// solution 
bool included[n];
int soln=0;

int calc_sum(int i){
    if(i==n){
        return 0;
    }

    return (set[i] + calc_sum(++i));
}

int get_total(int ind){
    int t=calc_sum(0);

    for(int i=0;i<=ind;i++){
        t-=set[i];
    }
    return t;
}
int find_last_included(){
    for(int i=n-1;i>=0;i--){
        if(included[i]==1){
            included[i]=0;
            return i;
        }
    }
    return -1;
}

void solve(int wi,int total,int index){
    if(wi == sum){
        
        soln++;
        cout<<"{ ";
        for(int i=0;i<n;i++){
            if(included[i]){
                cout<<set[i]<<" ";

            }
        }
        cout<<"}"<<endl;
        
        int ind=find_last_included();
       
        wi-=set[ind];
        solve(wi,total,ind+1);
    }


    if(wi + total >= sum){

        if(wi + set[index] <= sum){
            included[index]=1;
            wi+=set[index];
            total-=set[index];
            solve(wi,total,++index);
        }else{            
            total-=set[index];
            solve(wi,total,++index);
        }

    }else{

        int ind=find_last_included();
        if(ind == -1){
            if(soln==0) cout<<"no solution exist\n";
            return;
        }

        wi-=set[ind];
        total=get_total(ind);
        solve(wi,total,ind+1);
    }

}


int main(){
    int wi=0;
    int total=calc_sum(0);
    system("cls");
    cout<<"given set: { ";
    for(int i=0;i<n;i++){
        cout<<set[i]<<" ";
    }
    cout<<"}"<<endl<<"sum required= "<<sum<<endl;

    solve(wi,total,0);
    cout<<"=> "<<soln<<" subset exist."<<endl;
}