class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int ans = 0;
        int openBracket = 0;

        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '(') openBracket++;

            if(s[i] == ')'){
                if(openBracket > 0){
                    openBracket--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans + openBracket;

        
    }
};
