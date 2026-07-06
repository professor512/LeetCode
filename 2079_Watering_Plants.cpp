class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int pos = -1;
        int fullCap = capacity;

        for(int i = 0; i < plants.size(); i++){
            
            if(capacity > plants[i]){
                steps += 1;
                capacity = capacity - plants[i];
                pos = i;
            }
            if(capacity < plants[i]){
                capacity = fullCap;
                capacity = capacity - plants[i];
                steps = 2 * pos + 1;
                pos = i;
            }
        }
        return steps;
    }
};
