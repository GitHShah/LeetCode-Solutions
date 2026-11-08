
class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        // Step 1: Find the first index where nums and target differ
        int idx = 0;
        while (idx < n && nums[idx] == target[idx]) {
            idx++;
        }

        int maxi;

        if (idx == n) {
            // Both arrays are already equal
            // Start checking from the last element
            idx = n - 1;
            maxi = nums[idx];
        } 
        else {
            // Step 2: Extract the suffix starting from idx
            vector<int> suffix(nums.begin() + idx, nums.end());

            // Sort the suffix in descending order
            sort(suffix.rbegin(), suffix.rend());

            // Step 3: Check if the sorted suffix matches target
            for (int i = 0; i < suffix.size(); i++) {
                if (suffix[i] != target[idx + i]) {
                    return 0;
                }
            }

            // Maximum element of the sorted suffix
            maxi = suffix[0];
        }

        // Step 4: Expand the valid suffix towards the left
        int ans = 1;

        for (int i = idx - 1; i >= 0; i--) {
            // We can extend only if the current element
            // is >= the maximum element seen so far
            if (nums[i] < maxi) {
                break;
            }

            maxi = nums[i];
            ans++;
        }

        return ans;
    }
};
