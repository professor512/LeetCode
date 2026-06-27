class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int smallest = INT_MAX, largest = INT_MIN;
        for(int i = 0; i < nums.size(); i++){

            if(nums[i] < smallest) smallest = nums[i];

            if(nums[i] > largest) largest = nums[i];
        }

        if(smallest == largest) return smallest;

        else if(largest % smallest == 0) return smallest;

        else{
            int cntr = smallest;
            while(cntr > 0){
                cntr -= 1;
                if(largest % cntr == 0 && smallest % cntr == 0) return cntr;
            }
        }
        return 1;
    }
};
