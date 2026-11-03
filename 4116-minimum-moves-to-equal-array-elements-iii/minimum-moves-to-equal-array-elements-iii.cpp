class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int ans = 0 ;

        for(int i = 0 ; i < n ; i++){
            maxi = max(nums[i],maxi);
        }

        for(int i = 0 ; i < n ; i++){
            ans+=(maxi-nums[i]);
        }

        return ans;
    }

    
};