class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int largest = nums.back();
        int smallest = nums.front();

        vector<int> ans;

        for(int i = smallest; i <= largest; i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()){
                ans.push_back(i);
            }
        }

        return ans;


        
    }
};
