class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int mini = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            mini = min(nums[i],mini);
        }

        for(int i = 0 ; i < n ; i++){
            ans+=(nums[i]-mini);
        }

        return ans;


    }
};