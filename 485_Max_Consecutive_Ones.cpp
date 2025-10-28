// https://leetcode.com/problems/max-consecutive-ones/submissions/1813877602/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxi = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                maxi = max(cnt, maxi);
            }
            else{
                cnt = 0;
            }
        }

        return maxi;
    }
};
