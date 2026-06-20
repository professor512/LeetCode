class Solution {
public:
    int maxDepth(string s) {
        int maxD = 0;
        int cnt = 0;

        for(char ch : s){
            if(ch == '('){
                cnt++;
                maxD = max(maxD, cnt);
            }
            else if(ch == ')'){
                cnt--;
            }
        }
        return maxD;
    }
};
