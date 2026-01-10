// Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, el;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cnt++;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        if(cnt > 0) return el;
        return -1;
    }
};

// {N + N, 1}
// Other N is not required if we are sure that majority element always exists
