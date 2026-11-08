class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]){

                    int cnt = 0;

                    for(int k = 0 ; k < m ; k++){
                        if(grid[k][j])
                            cnt++;
                    }

                    for(int k = 0 ; k < n ; k++){
                        if(grid[i][k])
                            cnt++;
                    }

                    if(cnt>2){
                        ans++;
                    }
                }
            }
        }


        return ans;
    }
};