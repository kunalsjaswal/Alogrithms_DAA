#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int sum=0;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	
	for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
	        int temp=arr[i] & arr[j];
	        sum+=temp;
        }
	}
	cout<<sum;
	return 0;
}
