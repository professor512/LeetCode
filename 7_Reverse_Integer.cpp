class Solution {
public:
    int reverse(int x) {
        
        string str = to_string(x);

        bool negative = x < 0;

        if(negative)
            str = str.substr(1);
        
        std::reverse(str.begin(), str.end());

        long long ans = stoll(str);

        if(negative) ans = -ans;

        if(ans > INT_MAX || ans < INT_MIN)
            return 0;
        
        return ans;
    }
};
