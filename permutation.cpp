#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int arr[]={1,2,3};
	next_permutation(arr,arr+3);
	for(int i =0;i<3;i++)
		printf("%d ",arr[i]); 
	return 0;
} 
