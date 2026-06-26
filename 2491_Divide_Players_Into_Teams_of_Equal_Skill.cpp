class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

       int n = skill.size();

       int left = 0;
       int right = n - 1;

       sort(skill.begin(), skill.end());

        long long ans = 0;
        long long temp = 0;

       while(left < right){
        
        long long currSum = skill[left]+skill[right];

        if(temp == 0){
            temp = currSum;
        }
        else if(currSum != temp) return -1;

        ans += skill[left] * skill[right];
        left++;
        right--;

        
       }

        return ans;
       
    }
};
