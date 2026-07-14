class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        
        map<int, int>mp;

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == key){
                mp[nums[i+1]]++;
            }
        }
        int maxFreq = 0;
        int ansKey = -1;

        for(auto [k, freq] : mp){
            if(freq > maxFreq){
                maxFreq = freq;
                ansKey = k;
            }
        }

        return ansKey;
    }
};
