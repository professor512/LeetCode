class Solution {
public:
    bool isPalindrome(int x) {
        
        int y = x;
        long long z = 0;

        while(y > 0){

            z = z * 10 + (y % 10);
            y /= 10;

        }

        return z == x;
    }
};
