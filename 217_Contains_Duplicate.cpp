class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int x : nums){
            if(st.count(x))
                return true;
            st.insert(x);
        }

        return false;
    }
};

// count() returns 0, 1 based on element present or not
