class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf0(m, -1);
        vector<int> suf1(m, -1);

        for (int i = m - 1; i >= 0; i--) {


            int limit = (i == m - 1) ? n : suf0[i + 1];

            for (int p = limit - 1; p >= 0; p--) {
                if (word1[p] == word2[i]) {
                    suf0[i] = p;
                    break;
                }
            }


            int best = -1;

            
            limit = (i == m - 1) ? n : suf1[i + 1];

            for (int p = limit - 1; p >= 0; p--) {
                if (word1[p] == word2[i]) {
                    best = max(best, p);
                    break;
                }
            }

           
            limit = (i == m - 1) ? n : suf0[i + 1];

            if (limit > 0) {
                best = max(best, limit - 1);
            }

            suf1[i] = best;
        }

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        for (int i = 0; i < m; i++) {

            bool found = false;

            while (pos < n) {

                
                if (word1[pos] == word2[i]) {

                    if (i == m - 1 || suf1[i + 1] > pos) {
                        ans.push_back(pos);
                        pos++;
                        found = true;
                        break;
                    }
                }

                else if (!usedMismatch) {

                    if (i == m - 1 || suf0[i + 1] > pos) {
                        ans.push_back(pos);
                        pos++;
                        usedMismatch = true;
                        found = true;
                        break;
                    }
                }

                pos++;
            }

            if (!found)
                return {};
        }

        return ans;
    }
};
