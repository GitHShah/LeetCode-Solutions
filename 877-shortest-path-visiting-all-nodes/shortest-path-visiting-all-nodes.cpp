class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<long long>>dp(n,vector<long long>(1<<n,INT_MAX));
        queue<tuple<int, int, int>> q;
        set<pair<int,int>>vis;

        for(int i = 0 ; i < n ; i++){
            dp[i][1<<i]=0;
            q.push({i,1<<i,0});
        }

        while(!q.empty()){
            auto [a, b, c] = q.front();
            q.pop();

            if(vis.find({a,b})!=vis.end()){
                continue;
            }

            int sz = graph[a].size();

            for(int j = 0 ; j < sz ; j++){
                q.push({graph[a][j],(1<<graph[a][j])|b , c+1});
                if(c+1<dp[graph[a][j]][(1<<graph[a][j])|b])
                    dp[graph[a][j]][(1<<graph[a][j])|b]=c+1;
            }

            vis.insert({a,b});

        }

        long long ans = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            ans = min(dp[i][(1<<n)-1],ans);
        }

        return ans;
        
    }
};