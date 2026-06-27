class Solution {
public:
    bool consecutiveSetBits(int n) {

        string binary = bitset<32>(n).to_string();
        int count = 0;
        for(int i = 0; i < binary.size() - 1; i++){
            if(binary[i] == '1' && binary[i+1] == '1') count++;
        }
        
        return count == 1;
    }
};
