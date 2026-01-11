// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        int nextPos = 0;
        int nextNeg = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[nextPos] = nums[i];
                nextPos += 2;
            }
            else{
                ans[nextNeg] = nums[i];
                nextNeg += 2;
            }
        }

        return ans;
    }
};

// {N, N}
