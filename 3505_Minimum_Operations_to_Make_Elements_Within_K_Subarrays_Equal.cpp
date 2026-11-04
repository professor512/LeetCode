
class Solution {
public:
    multiset<int> small, large;
    long long smallSum = 0, largeSum = 0;

    void balance() {
        int target = (small.size() + large.size() + 1) / 2;

        while (small.size() > target) {
            auto it = prev(small.end());
            int val = *it;

            small.erase(it);
            smallSum -= val;

            large.insert(val);
            largeSum += val;
        }

        while (small.size() < target) {
            auto it = large.begin();
            int val = *it;

            large.erase(it);
            largeSum -= val;

            small.insert(val);
            smallSum += val;
        }
    }

    void add(int val) {
        if (small.empty() || val <= *small.rbegin()) {
            small.insert(val);
            smallSum += val;
        } else {
            large.insert(val);
            largeSum += val;
        }
        balance();
    }

    void remove(int val) {
        auto it = small.find(val);

        if (it != small.end()) {
            small.erase(it);
            smallSum -= val;
        } else {
            it = large.find(val);
            large.erase(it);
            largeSum -= val;
        }
        balance();
    }

    long long getCost() {
        long long med = *small.rbegin();

        return med * small.size() - smallSum
             + largeSum - med * large.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        // Calculate sliding window costs
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // Optimized DP
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select window ending at i-1
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            swap(prev, curr);
        }

        return prev[n];
    }
};
