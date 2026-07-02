class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans;

        int i = 0, n = nums.size() - 1;

        while(i <= n){
            if(nums[i] == target){
                ans.push_back(i);
                break;
            }
            i++;
        }
        while(n >= 0){
            if(nums[n] == target){
                ans.push_back(n);
                break;
            }
            n--;
        }
        if(ans.empty()) return {-1, -1};

        return ans;
    }
};
