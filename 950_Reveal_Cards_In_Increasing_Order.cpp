class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        queue<int> Q;

        for(int i = 0; i < deck.size(); i++){
            Q.push(i);
        }

        vector<int>ans(n);

        for(int card : deck){
            int index = Q.front();
            Q.pop();

            ans[index] = card;

            if(!Q.empty()){
                Q.push(Q.front());
                Q.pop();
            }
        }
        return ans;
    }
};
