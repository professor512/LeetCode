class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int>freq;

        for(int n : nums){
            freq[n]++;
        }

        vector<int>ans;

        for(auto it : freq){
            if(it.second > 1) ans.push_back(it.first);
        }

        return ans;

    }
};
