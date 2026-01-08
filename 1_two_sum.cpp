class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            int moreReq = target - a;
            if(mpp.find(moreReq) != mpp.end()){
                return {mpp[moreReq], i};
            }
            mpp[a] = i;
        }
        return {-1,-1};
    }
};
