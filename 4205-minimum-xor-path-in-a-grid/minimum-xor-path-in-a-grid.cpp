class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        std::vector<std::vector<std::vector<int>>> dp(m, std::vector<std::vector<int>>(n, std::vector<int>(1024, 0)));

        dp[0][0][grid[0][0]]=1;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i==0 && j==0){
                    continue;
                }

                bitset<1024>combine;

                if(i-1>=0){
                    for(int k = 0 ; k < 1024 ; k++){
                        if(dp[i-1][j][k]){
                            combine[k]=1;
                        }
                    }
                }

                if(j-1>=0){
                    for(int k = 0 ; k < 1024 ; k++){
                        if(dp[i][j-1][k]){
                            combine[k]=1;
                        }
                    }
                }

                for(int k = 0 ; k < 1024 ; k++){
                    if(combine[k]){
                        dp[i][j][(k)^(grid[i][j])]=1;
                    }
                }
            }
        }


        for(int i = 0 ; i < 1024 ; i++){
            if(dp[m-1][n-1][i]){
                return i;
            }
        }

        return 69;


    }
};