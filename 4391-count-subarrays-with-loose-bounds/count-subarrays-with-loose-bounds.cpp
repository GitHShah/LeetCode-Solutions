class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0 ;
        int n = nums.size();

        int start = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                ans+=(i-start+1);
            }else{
                start = i+1;
            }

            
        }
        return ans;
    }
};