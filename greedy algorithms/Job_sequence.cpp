#include<iostream>
using namespace std;

const int jobs=5;
int profits[jobs]={60,100,20,40,20};
int deadline[jobs]={2,1,3,2,1};

int sequence[jobs];
void fill_s(){
    for(int i=0;i<jobs;i++){
        sequence[i]=-1;
    }
}

int find_max(int *value){
    int m=profits[0];
    int k=0;
    for(int i=1;i<jobs;i++){
        if(profits[i]>m){
            m=profits[i];
            k=i;
        }
    }
    *value=profits[k];
    profits[k]=0;
    return k;
}

int find_possible(){
    int n=deadline[0];
    for(int i=1;i<jobs;i++){
        if(deadline[i] > n){
            n=deadline[i];
        }
    }

    return n;
}

int job_sequence(int n){

    int p=0;
    int value;

    while(n>0){

        int max_profit=find_max(&value);

        // if no job is remaining but still there is space between array.
        if(value == 0){
            return p;
        }
        while(deadline[max_profit] >0){
            if(sequence[deadline[max_profit]]==-1){
                sequence[deadline[max_profit]]=max_profit;
                p+=value;
                n--;
                break;
            }
            deadline[max_profit]--;
        }
    }
    return p;
}

void display(){
    for(int i=0;i<jobs;i++){
        if(sequence[i]!=-1){
            cout<<"Job "<<sequence[i]+1<<" -> ";
        }
    }
    cout<<"No job available."<<endl;
}

int main(){
    fill_s();

    int possible_jobs=find_possible();

    int max_profit=job_sequence(possible_jobs);

    system("cls");

    display();
    cout<<"maximum profit: "<<max_profit<<endl;

}