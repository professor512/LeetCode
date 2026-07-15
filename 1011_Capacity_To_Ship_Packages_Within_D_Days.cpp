class Solution {
public:

    bool checkCapacity(vector<int>&weights, int days, int capacity){
        int currW = 0;
        int daysUsed = 1;
        
        for(int w : weights){
            if(currW + w <= capacity){
                currW += w;
            }
            else{
                daysUsed++;
                currW = w;
            }
        }
        return daysUsed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while(left <= right){
            
            int mid = (right + left) / 2;

            if(checkCapacity(weights, days, mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }


        }
        return left;
    }
};
