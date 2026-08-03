class Solution {
public:
    void countWords(string s, unordered_map<string, int> &mp){
        string word = "";
        for(char c : s){
            if(c == ' '){
                mp[word]++;
                word = "";
            }
            else{
                word += c;
            }
        }
        mp[word]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        countWords(s1, mp);
        countWords(s2, mp);

        vector<string> ans;

        for(auto it : mp){
            if(it.second == 1)
                ans.push_back(it.first);
        }

        return ans;

    }
};
