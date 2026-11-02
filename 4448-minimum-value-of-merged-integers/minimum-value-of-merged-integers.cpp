class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        for(int i = 0 ; i < n ; i+=2){
            string s1 = to_string(nums[i]);
            string s2 = to_string(nums[i+1]);

            string s = s1+s2;

            ans = min(stoi(s),ans);
        }

        return ans;
    }
};