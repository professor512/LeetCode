class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       vector<int> freq(100001, 0);

       for(int c:costs) freq[c]++;


       int ans = 0;

       for(int i = 1; i < freq.size(); i++){
            if(freq[i] == 0) continue;

            int currFreq = freq[i];

            while(currFreq > 0 && coins >= i){
                coins -= i;
                currFreq--;
                ans++;
            }

       }

       return ans;

    }
};
