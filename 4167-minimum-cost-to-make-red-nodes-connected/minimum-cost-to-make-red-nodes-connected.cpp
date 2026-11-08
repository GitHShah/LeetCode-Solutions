class Solution {
public:
    vector<vector<int>> graph;
    vector<int> sz;
    vector<array<long long, 3>> dp;

    void dfs(int u, string &colors) {
        sz[u] = 1;

        for (int v : graph[u]) {
            dfs(v, colors);
            sz[u] += sz[v];
        }

        long long red = (colors[u] == 'R') ? 0 : sz[u];
        long long blue = (colors[u] == 'B') ? 0 : sz[u];

        dp[u][0] = blue;
        dp[u][1] = red;
        dp[u][2] = LLONG_MAX / 4;

        for (int v : graph[u]) {
            dp[u][0] += dp[v][0];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }

        for (int v : graph[u]) {
            dp[u][2] = min(dp[u][2],
                dp[u][0] - dp[v][0]
                + min(dp[v][1], dp[v][2]));
        }
    }

    long long minCost(int n, string colors,
                      vector<vector<int>>& edges) {

        graph.resize(n);
        sz.resize(n);
        dp.resize(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
        }

        dfs(0, colors);

        return min({dp[0][0], dp[0][1], dp[0][2]});
    }
};