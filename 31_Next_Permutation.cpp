// Next Greater Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index != -1){
            for(int i = n-1; i > index; i--){
                if(nums[i] > nums[index]){
                    swap(nums[i], nums[index]);
                    break;
                }
            }

            reverse(nums.begin()+index+1, nums.end());
        }
        else{
            reverse(nums.begin(), nums.end());
        }

        
    }
};

// {3N, 1}
