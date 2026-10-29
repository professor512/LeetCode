
class Solution {
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, bit;
    vector<int> fenwick;
    int timer, LOG;

    void add(int idx, int val) {
        for (; idx < fenwick.size(); idx += idx & -idx)
            fenwick[idx] ^= val;
    }

    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res ^= fenwick[idx];
        return res;
    }

    void dfs(int u, int p) {
        up[0][u] = p;
        tin[u] = ++timer;

        for (int j = 1; j < LOG; j++)
            up[j][u] = up[j - 1][up[j - 1][u]];

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = ++timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[j][u];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        adj.assign(n, {});
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));
        bit.resize(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
            bit[i] = 1 << (s[i] - 'a');

        timer = 0;
        dfs(0, 0);

        fenwick.assign(2 * n + 2, 0);

        for (int i = 0; i < n; i++) {
            add(tin[i], bit[i]);
            add(tout[i], bit[i]);
        }

        vector<bool> ans;

        for (string &q : queries) {
            string op;
            int u;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int newBit = 1 << (c - 'a');
                int delta = bit[u] ^ newBit;

                if (delta != 0) {
                    add(tin[u], delta);
                    add(tout[u], delta);
                    bit[u] = newBit;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = sum(tin[u])
                         ^ sum(tin[v])
                         ^ bit[w];

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
