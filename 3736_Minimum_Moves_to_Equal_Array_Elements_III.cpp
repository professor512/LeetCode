class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int mvs = 0;
         int maxi = *max_element(nums.begin(), nums.end());

         for(int x : nums){
            if(x != maxi){
                mvs = mvs + (maxi - x);
            }
         }
        return mvs;
    }
};
