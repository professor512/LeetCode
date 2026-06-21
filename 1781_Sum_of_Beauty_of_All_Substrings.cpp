class Solution {
public:
    int beautySum(string s) {
        
        int sum = 0;

        for(int i = 0; i< s.size(); i++){

            int arr[26] = {0};
            
            for(int j = i; j < s.size(); j++){
                int charFreq = s[j] - 'a';
                 arr[charFreq]++;

                 int mx = *max_element(arr, arr +26);
                 int mn = mx;

                 for(int k = 0; k < 26; k++){
                    if(arr[k] > 0){
                        mn = min(mn, arr[k]);
                    }
                 }
                 
                 
                 int beauty = mx - mn;
                 sum += beauty;
            }
        }
        return sum;
    }
};
