class Solution {
public:
    int n , x , k;
    long long minOpsSubarray[100001];
    long long dp[16][100001];

    long long solve(int cnt , int i){
        if(cnt==k){
            return 0;
        }

        int req = k-cnt;
        int EleNeed = req*x;
        int final = i+EleNeed-1;

        if(final>=n){
            return 1e16;
        }

        if(dp[cnt][i]!=-1){
            return dp[cnt][i];
        }

        long long result = minOpsSubarray[i]+solve(cnt+1,i+x);
        result = min(result,solve(cnt,i+1));

        return dp[cnt][i]=result;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        this->n = nums.size();
        this->x = x;
        this->k = k;

        memset(dp, -1, sizeof(dp));

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            if(left.size() <= right.size()) {
                left.insert(nums[j]);
                leftSum += nums[j];
            } else {
                right.insert(nums[j]);
                rightSum += nums[j];
            }


            if(!left.empty() && !right.empty()) {
                int maxLeft  = *left.rbegin();
                int minRight = *right.begin();

                if(maxLeft > minRight) {
                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));

                    left.insert(minRight);
                    right.insert(maxLeft);

                    leftSum += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }

            if(j-i+1 == x) {
                long long median = *left.rbegin();
                long long leftSize = left.size();
                long long rightSize = right.size();

                minOpsSubarray[i] = (leftSize * median - leftSum) + (rightSum - rightSize*median);

                if(left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                } else {
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }
                i++;
            }

            j++;
        }

        return solve(0, 0);

    }
};