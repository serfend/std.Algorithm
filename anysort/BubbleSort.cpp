#include <iostream>
#include <vector>
using namespace std;
typedef int Rank;
template <typename T>
Rank bubble(vector<T>& v,Rank lo,Rank hi){
	Rank last=lo;
	while(++lo<hi){
		if(v[lo-1]>v[lo]){
			last=lo;
			swap(v[lo-1],v[lo]);
		}
	} 
	return last;
} 
template <typename T>
void BuubleSort(vector<T>& v,Rank lo,Rank hi){
	while(lo<(hi=bubble(v,lo,hi)));
}

int main(){
	vector<int>v;
	v.push_back(44);
	v.push_back(33);
	v.push_back(22);
	v.push_back(11);
	v.push_back(55);
	BuubleSort(v,(Rank)0,(Rank)v.size());
	for(int i=0;i<5;i++){
		printf("%d\n",v[i]);
	}
	return 0;
} 
