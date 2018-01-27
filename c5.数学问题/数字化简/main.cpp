#include <iostream>
#include <math.h>
#define MAX 100010
struct factor{
	int index;
	int num;
}f[MAX];
bool isPrime(int n){
	for(int i=2;i<sqrt(n);i++){
		if(n%i==0)return false;
	}
	return true;
}
void init(){
	int i=2;
	for(int count=0;count<MAX;count++){
		for(;!isPrime(i);i++);
		f[count].index=i++;
	}
}
int main(int argc, char** argv) {
	int n;
	init();
	scanf("%d",&n);
	if(n==1){
		printf("1=1");
		return 0; 
	}
	printf("%d=",n);
	for(int i=0;i<MAX;i++){
		while(n%f[i].index==0){
			n/=f[i].index;
			f[i].num++;
		}
		
		switch(f[i].num){
			case 0:{
				break;
			}
			case 1:{
				printf("%d*",f[i].index);
				break;
			}
			default:{
				printf("%d^%d*",f[i].index,f[i].num);
				break;
			}
		}
		if(n==1)break;
	}
	if(n!=1){
		printf("%d",n);
	}else{
		printf("\b ");
	}
	return 0;
}
