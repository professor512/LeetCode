class Solution {
public:
    int arrangeCoins(int n) {
        int cnt = 0;
        int lastStep = 0;
        for(int i = 1; i <= n; i++){
            if(n >= i){
                cnt++;
                n -= i;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};
