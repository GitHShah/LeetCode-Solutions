class Solution {
public:
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};

    bool dfs(int i , int j , vector<vector<bool>>&vis , vector<vector<int>>& grid ){
        int m = grid.size();
        int n = grid[0].size();

        if(i==m-1 || j==n-1 || i==0 || j==0){
            return false;
        }
        
        bool chk = true;
        vis[i][j]=true;
        for(int t = 0 ; t < 4 ; t++){
            int x1 = i + x[t];
            int y1 = j + y[t];

            if(x1>=0 && x1<m && y1>=0 && y1<n && grid[x1][y1]==0 && !vis[x1][y1] ){
                if(!dfs(x1,y1,vis,grid))
                    chk = false;
            }
        }
        return chk;
    }

    int closedIsland(vector<vector<int>>& grid) {
        // m*n size
        int m = grid.size();
        int n = grid[0].size();

        int ans =  0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                //cout << "i" << " " << i << " ";
                //cout << "j" << " " << j << endl; 
                if(grid[i][j]==0 && vis[i][j]==false){
                    //cout << "cond1" << endl;
                    if(dfs(i,j,vis,grid)){
                        //cout << "cond2"<<endl;
                        ans++;
                        //cout << ans << endl;
                    }
                        
                }
            }
            cout << "---" <<endl;
        }

        return ans;



    }
};