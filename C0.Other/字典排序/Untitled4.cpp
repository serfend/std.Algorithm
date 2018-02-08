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
        return false; //空序列  
  
    BidirectionalIterator i = first;  
    ++i;  
    if(i == last)  
        return false;  //一个元素，没有下一个序列了  
      
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
            reverse(first, last);  //全逆向，即为最小字典序列，如cba变为abc  
            return false;  
        }  
    }  
  
}  
int main()  
{  
    char a[5]={'a','b','c','d','e'};//第一个排列保证正序，有时候根据题目要求，需要对其进行排序处理。  
    for(int i=1;i<=720;i++)//i为总共排列的个数  ，及 3！  
    {  
        for(int j=0;j<5;j++)  
            cout<<a[j]<<" ";  
        cout<<endl;  
        mynext_permutation(a,a+5);//放在第一个排列的后边，输出第一个排列的下一个排列  
    }  
    return 0;  
}  
