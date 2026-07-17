class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        for(string str : sentences){
            int words = 1;
            for(char ch : str){
                if(ch == ' ') words++;
            }
            maxWords = max(maxWords, words);
        }

        return maxWords;
    }
};
