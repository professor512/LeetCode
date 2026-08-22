class Solution {
public:
    bool checkDivisibility(int n) {
        
        int num = n;
        int sum = 0;
        int prod = 1;

        while(n > 0){
            int digit = n % 10;

            sum += digit;
            prod *= digit;

            n /= 10;
        }

        return num % (sum + prod) == 0;
    }
};
