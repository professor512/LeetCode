class Solution {
public:
    string smallestPalindrome(string s) {
        
        string str1, str2, str3;
        vector<int>freq(26, 0);

        for(char ch : s){
            freq[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            char ch = i + 'a';

            if(freq[i] % 2 == 0){
                str1.append(freq[i] / 2, ch);
                str2.append(freq[i] / 2, ch);
            }
            else{
                str1.append(freq[i] / 2, ch);
                str2.append(freq[i] / 2, ch);
                str3.push_back(ch);

            }
        }




        reverse(str2.begin(), str2.end());

        return str1 + str3 + str2;
    }
};
