#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int majorityElement(vector<int>& nums){
    int len=nums.size();
    int candi=-1;
    int count=0;
    for(int i=0;i<len;i++){
        if(nums[i]==candi){
            count++;
        }else if(--count<0){
            candi=nums[i];
            count=1;
        }
    }
    return candi;
}