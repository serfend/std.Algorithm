#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void Mergesort(vector<T>& v,int lo,int mi,int hi){
	if(lo>=mi)return;
	if(mi>=hi)return;
	T* A=&v[lo];
	int lb=mi-lo;
	T* B=new T[lb];
	for(int i=0;i<lb;B[i]=A[i++]);
	int lc=hi-mi;
	T* C=&v[mi];
	for(int i=0,j=0,k=0;j<lb;){
		if((j<lb)&&B[j]<=C[k])A[i++]=B[j++];
		if((k<lc)&&C[k]<B[j])A[i++]=C[k++];
	}
	delete [] B;
	Mergesort(v,lo,(mi+lo)/2,mi);
	Mergesort(v,mi,(mi+hi)/2,hi);
} 
template<typename T>
void MergeSort(vector<T>& v){
	Mergesort(v,0,v.size()/2,v.size());
}

int main(){
	vector<int>v;
	v.push_back(44);
	v.push_back(33);
	v.push_back(22);
	v.push_back(11);
	v.push_back(55);
	MergeSort(v);
	for(int i=0;i<5;i++){
		printf("%d\n",v[i]);
	}
	return 0;
} 
