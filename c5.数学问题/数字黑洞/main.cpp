#include <iostream>
#include <algorithm>
using namespace std;
void NumToArray(int n,int num[]){
	for(int i=3;i>=0;i--){
		num[i]=n%10;
		n/=10;
	}
}
int ArrayToNum(int num[],int n,bool reverse){
	int result=0;
	if(reverse){
		for(int i=0;i<n;i++){
			result*=10;
			result+=num[i];
		}
	}else{
		for(int i=n-1;i>=0;i--){
			result*=10;
			result+=num[i];
		}
	}

	return result;
}
bool cmp(int a,int b){
	return (a-b)>0;
}
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n); 
	int num[4];
	int maxNum,minNum,result;
	do{
		NumToArray(n,num);
		sort(num,num+4,cmp);
		minNum=ArrayToNum(num,4,false);
		maxNum=ArrayToNum(num,4,true);
		n=maxNum-minNum;
		printf("%04d - %04d = %04d\n",maxNum,minNum,n);
	}while(n!=0&&n!=6174);

	
	return 0;
}
