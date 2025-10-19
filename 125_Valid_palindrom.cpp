class Solution {
public:
    bool isPalindrome(string &s, int i = 0) {
        erase_if(s, [](unsigned char c) { return !std::isalnum(c); });
        if(i >= s.size() / 2) return true;

        if(tolower(s[i]) != tolower(s[s.size() - i - 1])) return false;

        return isPalindrome(s, i+1);
    }
};
