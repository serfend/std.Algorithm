#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
    bool cmpTmp(vector<int> a,vector<int> b){
        if(a[0]!=b[0])return a[0]-b[0];
        if(a[1]!=b[1])return a[1]-b[1];
        return a[2]-b[2];
    }
    vector<int> buildSolution(int a,int b,int c){
        vector<int> tmp;
        int tmpV[3];
        tmpV[0]=a,tmpV[1]=b,tmpV[2]=c;
        sort(tmpV,tmpV+3);
        tmp.push_back(tmpV[0]);
        tmp.push_back(tmpV[1]);
        tmp.push_back(tmpV[2]);
        return tmp;
    }
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > tmp;
        
        for(int i=0;i<nums.size()-2;i++)
            for(int j=i+1;j<nums.size()-1;j++){
                int thisNum=nums[i]+nums[j];
                for(int k=j+1;k<nums.size();k++){
                    if(thisNum==-nums[k]){
                        tmp.push_back(buildSolution(nums[i],nums[j],nums[k]));
                    }
                }
            }
        sort(tmp.begin(),tmp.end(),cmpTmp);
        return tmp;
    }

    int main(){
    	vector<int> a;
    	a.push_back(-1);
    	a.push_back(0);
    	a.push_back(1);
    	a.push_back(2);
    	a.push_back(-1);
    	a.push_back(-4);
    	printf("%d",threeSum(a).size()); 
	}
