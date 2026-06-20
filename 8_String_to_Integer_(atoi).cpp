class Solution {
public:
    
    int myAtoi(string s) {
        
        int sign = 1;
        string ans = "";
        int i = 0;
        long long result = 0;
        
        while(s[i] == ' '){
            i++;
        }

        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-') sign = -1;
            i++;
        }

        while(i < s.size() && isdigit(s[i])){

            int digit = s[i] - '0';
            result = result * 10 + digit;
            i++;

            if(result > INT_MAX && sign == 1) return INT_MAX;
            if(result > INT_MAX && sign == -1) return INT_MIN;
        }

        return sign * result;


    }
};
