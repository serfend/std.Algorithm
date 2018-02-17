#include <iostream>
unsigned short num[23333]={1};
int nowLen=1;
void show(){
	for(int i=nowLen-1;i>=0;i--)
		printf("%d",num[i]);
}
void muti(int n){
	int carry=0;
	for(int i=0;i<nowLen;i++){
		num[i]=num[i]*n+carry;
		carry=num[i]/10;
		num[i]%=10;
	}
	while(carry>0){
		num[nowLen++]=carry%10;
		carry/=10;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=n;i>0;i--){
		muti(i);
	}
	show();
	return 0;
} 
