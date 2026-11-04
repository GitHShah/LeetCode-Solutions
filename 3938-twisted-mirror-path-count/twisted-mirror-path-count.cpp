class Solution {
public:
    // right == 0 
    // down == 1
    long long dp[501][501][2];
    const long long mod = 1e9+7;

    long long solve(int i , int j , int dir , vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i==m-1 && j==n-1){
            return 1;
        }

        if(i<0 || i >= m || j < 0 || j>=n){
            return 0;
        }

        if(dp[i][j][dir]!=-1){
            return dp[i][j][dir];
        }

        int ans = 0;

        if(grid[i][j]){
            if(dir==0){
                ans= (ans + solve(i+1,j,1,grid))%mod;
            }else{
                ans=(ans+solve(i,j+1,0,grid))%mod;
            }
        }else{
            ans= (ans + solve(i+1,j,1,grid))%mod;
            ans=(ans+solve(i,j+1,0,grid))%mod;
        }

        return dp[i][j][dir]=ans;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(0,0,0,grid);


    }
};