class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        
        int n = capacity.size();

        vector<long long>prefixSum(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefixSum[i + 1] = prefixSum[i] + capacity[i];
        }

        map<pair<int, long long>, long long>mp;

        long long ans = 0;

        for(int r = 0; r < n; r++){
            if(r >= 2){
                int l = r - 2;
                mp[{capacity[l], prefixSum[l]}]++;
            }

            pair<int, long long> keyPair = {capacity[r], prefixSum[r] - 2 * capacity[r]};

            ans += mp[keyPair];
    


        }

        return ans;
    }
};
