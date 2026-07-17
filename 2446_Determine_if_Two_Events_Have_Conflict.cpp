class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int E1_start = stoi(event1[0].substr(0,2)) * 3600 + stoi(event1[0].substr(3,2)) * 60;
        int E1_end = stoi(event1[1].substr(0,2)) * 3600 + stoi(event1[1].substr(3,2)) * 60;

        int E2_start = stoi(event2[0].substr(0,2)) * 3600 + stoi(event2[0].substr(3,2)) * 60;
        int E2_end = stoi(event2[1].substr(0,2)) * 3600 + stoi(event2[1].substr(3,2)) * 60;

        if(E2_start >= E1_start && E2_start <= E1_end){
            return true;
        }
        if(E2_end >= E1_start && E2_end <= E1_end){
            return true;
        }
        if(E2_start <= E1_end && E2_end >= E1_end){
            return true;
        }

        return false;
    }
};
