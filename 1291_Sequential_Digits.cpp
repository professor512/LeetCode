class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";

        vector<int>ans;

        int l = to_string(low).size();
        int h = to_string(high).size();

        for(int length = l; length <= h; length++){
            for(int i = 0; i + length <= 9; i++){
                int num = stoi(str.substr(i, length));
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
                if(num >= high){
                    return ans;
                }
            }
        }
        return ans;
    }
};
