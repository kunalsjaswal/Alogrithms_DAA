#include<iostream>
using namespace std;

const int objects=4;

int profit[objects]={100,280,120,120};
int weight[objects]={10,40,20,24};
int capacity=60;



void swapping(int i,int c){

        profit[i]+=profit[c];
        profit[c]=profit[i]-profit[c];
        profit[i]-=profit[c];

        weight[i]+=weight[c];
        weight[c]=weight[i]-weight[c];
        weight[i]-=weight[c];

}



void selection_sort(){
    for(int i=0;i<objects-1;i++){
        double max_p_w=(double)profit[i]/weight[i];
        int c=i+1;
        bool flag=0;
        for(int j=i+1;j<objects;j++){
            if((double)profit[j]/weight[j] >max_p_w ){
                max_p_w=(double)profit[j]/weight[j];
                c=j;
                flag=1;
            }
        }
        if(flag){
            swapping(i,c);
        }
    }
}


double solve_problem(){
    double p=0;

    selection_sort();

    for(int i=0;i<objects;i++){
        
        if(capacity>0 && weight[i]<=capacity){
            p+=profit[i];
            capacity-=weight[i];
        }else if(capacity>0 && weight[i]>capacity){
            double p1=(double)capacity/weight[i];
            p+=profit[i]* p1;
            return p;
        }else{
            return p;
        }
    }

}

int main(){ 

double max_profit=solve_problem();

cout<<"Maimum profit is: "<<max_profit;
}