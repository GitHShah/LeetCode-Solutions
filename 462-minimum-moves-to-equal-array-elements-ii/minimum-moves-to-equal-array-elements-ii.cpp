class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());\
        int ans = INT_MAX;

        if(n%2==0){
            int mid1 = nums[n/2-1];
            int mid2 = nums[n/2];

            int ans1 = 0;
            int ans2 = 0;

            for(int i = 0 ; i < n ; i++){
                ans1+=abs(mid1-nums[i]);
                ans2+=abs(mid2-nums[i]);
            }

            ans = min(ans1,ans2);

        }else{
            int mid1 = nums[n/2];
            int ans1 = 0;

            for(int i = 0 ; i < n ; i++){
                ans1+=abs(mid1-nums[i]);
            }

            ans = ans1;

        }

        return ans;

    }
};