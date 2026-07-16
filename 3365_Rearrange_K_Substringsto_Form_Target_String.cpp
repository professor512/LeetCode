class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        
        unordered_map<string, int>parts;

        int len = s.size() / k;

        for(int i = 0; i < s.size(); i+= len){
            parts[s.substr(i, len)]++;
        }

        string str = "";

        for(int i = 0; i < t.size(); i+= len){
            string part = t.substr(i, len);
            
            if(parts[part] == 0) return false;

            parts[part]--;
        }

        return true;


    }
};
