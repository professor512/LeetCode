class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int arr[26] = {0};
        int i = 0;

        for(int i = 0; i < text.size(); i++){

            if(text[i] == 'b' || text[i] == 'a'|| text[i] == 'l' || text[i] == 'o' || text[i] == 'n'){
                int pos = text[i] - 'a';
                arr[pos]++;
            }

        }

        return min({arr['b' - 'a'], arr['a'-'a'], arr['l'-'a'] / 2, arr['o'-'a'] / 2, arr['n'-'a']});



        
    }
};
