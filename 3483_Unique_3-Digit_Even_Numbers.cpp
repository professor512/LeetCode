class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int n = digits.size();
        vector<int>freq(10, 0);

        for(int digit : digits){
            freq[digit]++;
        }

        int count = 0;

        for(int num = 100; num <= 999; num += 2){
            
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int>temp = freq;

            if(--temp[a] >= 0 && --temp[b] >= 0 && --temp[c] >= 0)
                count++;
        }

        return count;
    }
};
