class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>ans;
        char startCol = s[0];
        char startRow = s[1] - '0';
        char endCol = s[3];
        char endRow = s[4] - '0';

        for(char col = startCol; col <= endCol; col++){
            for(int row = startRow; row <= endRow; row++){
                string cell;
                cell += col;
                cell += to_string(row);
                ans.push_back(cell);
            }
        }

        return ans;
    }
};
