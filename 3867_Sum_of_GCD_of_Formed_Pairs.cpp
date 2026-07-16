class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        int mxi = 0;
        vector<int>prefixGcd;

        for(int i  = 0; i < nums.size(); i++){
            if(nums[i] > mxi) mxi = nums[i];

            prefixGcd.push_back(gcd(nums[i], mxi));
        }

        int i = 0, j = prefixGcd.size()-1;
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        while(i < j){
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;

    }
};
