#include<iostream>
#include<vector>
using namespace std;

const int jobs=5;

int jobs_name[jobs]={1,2,3,4,5};
int profits[jobs]={60,100,20,40,20};
int deadline[jobs]={3,1,3,3,1};


int sequence[jobs+1];

void swapping(int i,int j){
    profits[i]+=profits[j];
    profits[j]=profits[i]-profits[j];
    profits[i]-=profits[j];


    deadline[i]+=deadline[j];
    deadline[j]=deadline[i]-deadline[j];
    deadline[i]-=deadline[j];

    jobs_name[i]+=jobs_name[j];
    jobs_name[j]=jobs_name[i]-jobs_name[j];
    jobs_name[i]-=jobs_name[j];

}
void selection_sort(){
    for(int i=0;i<jobs-1;i++){
        int m=profits[i];
        int index=i;
        for(int j=i+1;j<jobs;j++){
            if(profits[j]>m){
                m=profits[j];
                index=j;
            }
        }
        if(i!=index){
            swapping(i,index);
        }
    }
}   

int job_sequence(){

    int p=0;
    // 1. sort the job in decreasing order
    selection_sort();

    // 2. traverse every job and fit into the result_set sequence
    for(int i=0;i<jobs;i++){
        if(sequence[deadline[i]]==0){
            sequence[deadline[i]]=jobs_name[i];
            p+=profits[i];
            continue;
        }else{
            --deadline[i];
            while (deadline[i]>0)
            {   
                if(sequence[deadline[i]]==0){
                    sequence[deadline[i]]=jobs_name[i];
                    p+=profits[i];
                    break;
                }
                deadline[i]--;
            }
            
        }
    }
    return p;
}

void display(){
    for(int ele:sequence){
        if(ele!=0){
            cout<<"Job "<<ele<<" -> ";
        }
    }
    cout<<"No job available."<<endl;
}

int main(){
    system("cls");
  
    int max_profit=job_sequence();

    display();
    cout<<"maximum profit: "<<max_profit<<endl;
}