class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeros = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){

            if(s[i] == '0'){
                zeros++;
            }
            else if(zeros > 0){
                ans = max(ans+1, zeros);
            } 
        }
        return ans;
    }
};
