#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    struct all_sum{
        int lsum,rsum,msum,isum;
    };
    all_sum converge(all_sum left,all_sum right){
        int lsum=max(left.isum+right.lsum,left.lsum);
        int rsum=max(left.rsum+right.isum,right.rsum);
        int isum=left.isum+right.isum;
        int msum=max(max(left.msum,right.msum),left.rsum+right.lsum);
        return (all_sum){lsum,rsum,msum,isum};
    }
    all_sum get(vector<int>&nums,int l,int r){
        if(l==r){
            return (all_sum){nums[l],nums[l],nums[l],nums[l]};
        }
        int m=(l+r)>>1;
        all_sum left=get(nums,l,m);
        all_sum right=get(nums,m+1,r);
        return converge(left,right);
    }
    int maxSubArray(vector<int>& nums) {
        return get(nums,0,nums.size()-1).msum;
    }
};