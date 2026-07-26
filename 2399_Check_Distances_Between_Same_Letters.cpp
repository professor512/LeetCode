class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        
        vector<int>lastPos(26,-1);

        for(int i = 0; i < s.size(); i++){

            if(lastPos[s[i] - 'a'] == -1){
                lastPos[s[i] - 'a'] = i;
                continue;
            }

            if((i - lastPos[s[i] - 'a']) - 1 != distance[s[i] - 'a']) return false;


        }
        return true;
    }
};
