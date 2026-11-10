class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>ans(n+1,INT_MAX);
        ans[0]=0;

        for(int i = 0 ; i < n ; i++){
            if(i+1<=n)
                ans[i+1] = min(ans[i+1],ans[i]+costs[i+1-1]+1);
            if(i+2<=n)
                ans[i+2] = min(ans[i+2],ans[i]+costs[i+2-1]+4);
            if(i+3<=n)
                ans[i+3] = min(ans[i+3],ans[i]+costs[i+3-1]+9);
        }

        return ans[n];
    }
};