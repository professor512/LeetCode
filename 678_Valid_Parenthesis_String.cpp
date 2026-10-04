class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' acts as ')'
                high++;  // '*' acts as '('
            }

            // Even the maximum possible '(' is negative
            if (high < 0)
                return false;

            // We can never have fewer than 0 unmatched '('
            if (low < 0)
                low = 0;
        }

        return low == 0;
    }
};
