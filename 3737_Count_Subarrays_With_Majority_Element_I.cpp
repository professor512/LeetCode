
// This is Brute Force O(n)^2
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(n);
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                freq[i] = 1;
            }
            else{
                freq[i] = -1;
            }
        }


        for(int i = 0; i < nums.size(); i++){
            int arrSum = 0;

            for(int j = i; j<nums.size(); j++){

                arrSum += freq[j];

                if(arrSum > 0) ans++;
                
            }
        }
        return ans;
    }
};
