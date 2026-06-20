class Solution {
public:
    static bool compare(pair<char, int> a, pair<char, int> b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        map<char, int>mpp;
        string ans = "";

        for(char ch : s){
            mpp[ch]++; 
        }

        vector<pair<char, int>> v;
        
        for(auto x : mpp){
            v.push_back(x);
        }
        sort(v.begin(), v.end(), compare);

        for(auto x : v){
            ans += string(x.second, x.first);
        }
       return ans;
    }
};
