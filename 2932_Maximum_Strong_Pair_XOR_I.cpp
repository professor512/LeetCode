class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxXor = -1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int x = nums[i];
                int y = nums[j];

                if(abs(x - y) <= min(x, y)){
                    int xored = x ^ y;
                    maxXor = max(maxXor, xored);
                }
            }
        }

        return maxXor;
    }
};
