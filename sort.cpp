#include <cstdio>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
private:
    int ans;
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort_(nums, 0, nums.size() - 1, k);
        if (ans) return ans;
        return nums[nums.size() - k];
    }
    void sort_(vector<int>& nums, int left, int right, int k) {
        if (left > right) return;
        int i = left, j = right, base = nums[left];
        while (i < j) {
            while (i < j && nums[j] >= base) j--;
            while (i < j && nums[i] <= base) i++;
            if (i < j) swap(nums[i], nums[j]);
        }
        nums[left] = nums[i];
        nums[i] = base;
        //printf("%d\n",nums[i]);
        if (i == nums.size() - k) {
            ans = nums[i];
            return;
        }
        else if (i > nums.size() - k) {
            sort_(nums, left, i - 1, k);
        }
        else {
            sort_(nums, i + 1, right, k);
        }
    }
};