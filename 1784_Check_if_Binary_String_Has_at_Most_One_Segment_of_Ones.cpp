class Solution {
public:
    bool checkOnesSegment(string s) {
    
    bool zeroSum = false;
    for(char ch : s){
        if(ch == '0')
            zeroSum = true;
        else if(zeroSum)
            return false;
    }

    return true;
    }
};
