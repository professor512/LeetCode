class Solution {
public:
    int minSteps(string s, string t) {
        
       vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        for (char c : t)
            freq[c - 'a']--;

        int ans = 0;

        for (int x : freq) {
            if (x > 0)
                ans += x;
        }

        return ans;

    }
};
