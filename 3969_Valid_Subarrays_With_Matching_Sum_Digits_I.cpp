class Solution {
public:
    int firstDigit(long long x){
        while(x >= 10){
            x /=10;
        }
        return x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0;
        int n = nums.size();
        vector<long long>prefix(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for(int l = 0; l < n; l++){
            for(int r = l; r < n; r++){
                long long sum = prefix[r + 1] - prefix[l];

                if(sum % 10 == x && firstDigit(sum) == x)
                    ans++;
            }
        }

        return ans;

    }
};
