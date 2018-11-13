#include <iostream>
#include <queue>
int n=0;
struct node{
	int value;
	int rank;
}num[9999];
bool cmp(node& a,node&b){
	return a.value-b.value;
}
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d",&num[n].value)!=EOF){
		num[n].rank=n;
		n++;
	};
	n--;
	sort(num,num+n,cmp);
	return 0;
} 
