class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int mid = nums[nums.size() / 2];

        int moves = 0;

        for(int x : nums){
            moves += (abs(mid - x));
        }

        return moves;
    }
};
