#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 1000002
bool isPrime[MAXN]; 
int prime[MAXN]={0},primeNum=0;
int numstart,numend;
using namespace std;
void init(){
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2;i<MAXN;i++){
		if(isPrime[i]){
			prime[primeNum++]=i;
			for(int j=2*i;j<=MAXN;j+=i){
				isPrime[j]=false;
			}
		}
	}
}
void getRange(int* a,int* b){
	for(int i=0;i<primeNum;i++){
		if(prime[i]>=numstart){
			*a=i;
			break;
		}
	}
	for(int i=*a;i<primeNum;i++){
		if(prime[i]>numend){
			*b=i-1;
			break;
		}
	}
}
int main(int argc, char** argv) {
	scanf("%d %d",&numstart,&numend);
	init();
//	getRange(&start,&end);
	int count=0;
	for(int i=numstart-1;i<numend-1;i++){
		
		if(++count==10){
			count=0;
			printf("%d\n",prime[i]);
		}else{
			printf("%d ",prime[i]);
		}
	}
	
	if(numend-1>=0)printf("%d",prime[numend-1]);
	return 0;
}
