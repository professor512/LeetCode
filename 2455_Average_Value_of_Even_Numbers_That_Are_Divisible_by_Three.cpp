class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int cnt = 0;
        for(int x : nums){
            if(x % 2 == 0 && x % 3 == 0){
                sum += x;
                cnt++;
            }
        }
        if(sum > 0) return sum/cnt;

        return 0;
    }
};
