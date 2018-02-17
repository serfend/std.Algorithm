/*
	果然还是太水了~ 
*/
#include <iostream>
#include <stack>
#include <map>
using namespace std;
class Caculator{
	map<char,int> op;
	stack<char>opinfo;
	struct node{
		bool isNum;
		char option;
		int value;
		void Show(){
			if(isNum){
				printf("%d",value); 
			}else{
				printf("%c",option);
			}
		}
		
	};
	stack<node>RPN;
	bool IsNumber(char info){
		return info>='0'&&info<='9';
	}
	int GetNumber(string info,int& index){
		int tmp=info[index++]-'0';
		while(IsNumber(info[index])){
			tmp=tmp*10+info[index++]-'0';
		};
		index--; 
		return tmp;
	}
	public:
	Caculator(){
		op['!']=6,op['^']=5;
		op['*']=4,op['/']=3;
		op['+']=2,op['-']=1;
		op['(']=op[')']=0;
		op['\0']=-1;
	}
	void evaluate(string expression){
		for(int i=0;i<expression.length();i++){
			node tmp;
			if(IsNumber(expression[i])){
				tmp.isNum=true;tmp.value=GetNumber(expression,i);
				RPN.push(tmp);
			}else{
				do{
					int opcmp;
					if(opinfo.empty()){
						opcmp=1;
					}else{
						opcmp=op[expression[i]]-op[opinfo.top()];
					}
					 
	//				opinfo.push(expression[i++]);
					if(opcmp<0){
						/*	如果当前优先级<之前的优先级 
							立即进行计算 
						*/
						tmp.isNum=false;tmp.option=opinfo.top();
						RPN.push(tmp);
						opinfo.pop();
					}else if(opcmp>0){
						opinfo.push(expression[i]); 
						break;
					}else{
						opinfo.pop();
						break;
					}
				}while(true);

			}
		}
	}
	double caculate(){
		while(!RPN.empty()){
			RPN.top().Show();
			RPN.pop();
		}
		return 0;
	}
	double caculate(string expression){
		evaluate(expression);
		return caculate();
	}
};
typedef Caculator cacu;
int main(){
	cacu a;
	printf("\n%lf",a.caculate("(1+2*3^4!/2-1)*2"));
	return 0;
}
