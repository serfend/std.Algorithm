#include <iostream>
using namespace  std;
#define Posi(T) ListNode<T>*
template <typename T>
struct ListNode{
	T data;
	Posi(T) pred;
	Posi(T) succ;
	ListNode(){
	
	}
	ListNode(T e,Posi(T)p=NULL,Posi(T)s=NULL)
		:data(e),pred(p),succ(s){
		
		}
	Posi(T) insertAsPred(T const& e);
	Posi(T) insertAsSucc(T const& e);
		
};
int main (){
	
	return 0;
}
