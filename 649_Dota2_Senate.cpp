class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQ;
        queue<int> direQ;

        int n = senate.size();

        for(int i = 0; i < n; i++){
            if(senate[i] == 'R') 
                radiantQ.push(i);
            else
                direQ.push(i);
            
        }
        
        while(!radiantQ.empty() && !direQ.empty()){
            int r = radiantQ.front();
            int d = direQ.front();

            radiantQ.pop();
            direQ.pop();

            if(r < d){
                radiantQ.push(r + n);
            }
            else{
                direQ.push(d + n);
            }
        }

        if(radiantQ.empty())
            return "Dire";
        
        return "Radiant";
    }
};
