class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEl = *min_element(nums.begin(), nums.end());

        int moves = 0;

        for(int n : nums){
            moves += n - minEl;
        }

        return moves;
    }
};
