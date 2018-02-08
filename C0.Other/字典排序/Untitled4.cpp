#include <algorithm>
#include <iostream>  
#include <string.h>  
  
using namespace std;  
template<class BidirectionalIterator>  
bool mynext_permutation(  
      BidirectionalIterator first,   
      BidirectionalIterator last  
)  
{  
    if(first == last)  
        return false; //������  
  
    BidirectionalIterator i = first;  
    ++i;  
    if(i == last)  
        return false;  //һ��Ԫ�أ�û����һ��������  
      
    i = last;  
    --i;  
  
    for(;;) {  
        BidirectionalIterator ii = i;  
        --i;  
        if(*i < *ii) {  
            BidirectionalIterator j = last;  
            while(!(*i < *--j));  
  
            iter_swap(i, j);  
            reverse(ii, last);  
            return true;  
        }  
          
        if(i == first) {  
            reverse(first, last);  //ȫ���򣬼�Ϊ��С�ֵ����У���cba��Ϊabc  
            return false;  
        }  
    }  
  
}  
int main()  
{  
    char a[5]={'a','b','c','d','e'};//��һ�����б�֤������ʱ�������ĿҪ����Ҫ�������������  
    for(int i=1;i<=720;i++)//iΪ�ܹ����еĸ���  ���� 3��  
    {  
        for(int j=0;j<5;j++)  
            cout<<a[j]<<" ";  
        cout<<endl;  
        mynext_permutation(a,a+5);//���ڵ�һ�����еĺ�ߣ������һ�����е���һ������  
    }  
    return 0;  
}  
