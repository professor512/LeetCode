class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int total = 0;
        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;

        for(int num : nums){
            total += num;

            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);


        }

        if(maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }

};
