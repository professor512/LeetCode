
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (k >= total) return 0;

        // Minimum possible maximum difference
        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                needed += max(0, d - mid);
            }

            if (needed <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int limit = low;
        long long used = 0;
        long long ans = 0;

        for (int d : diff) {
            used += max(0, d - limit);

            long long remaining = min(d, limit);
            ans += remaining * remaining;
        }

        // Use leftover operations to reduce values
        // currently equal to limit by one more.
        long long extra = k - used;

        for (int d : diff) {
            if (extra == 0) break;

            if (d >= limit) {
                ans -= 2LL * limit - 1;
                extra--;
            }
        }

        return ans;
    }
};
