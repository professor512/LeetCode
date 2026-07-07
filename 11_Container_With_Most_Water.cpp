class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;


        while(l < r){
            int area = (r - l) * min(height[l], height[r]);
            ans = max(ans, area);

            if(height[r] > height[l]){
                l++;
            }
            else{
                r--;
            }

        }

        return ans;
    }
};

// simple 2 pointer solution
