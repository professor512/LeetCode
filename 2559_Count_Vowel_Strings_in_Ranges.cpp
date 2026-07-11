class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
       
      int n = words.size();
      vector<int>prefix(n+1, 0);
      vector<int>ans;


      for(int i = 0; i < n; i++){

        prefix[i + 1] = prefix[i];

        if(isVowel(words[i].front()) && isVowel(words[i].back())){
            prefix[i+1]++;

        }
      }

      for(auto q : queries){
        int l = q[0];
        int r = q[1];

        ans.push_back(prefix[r+1] - prefix[l]);
      }

      return ans;

    }
};
