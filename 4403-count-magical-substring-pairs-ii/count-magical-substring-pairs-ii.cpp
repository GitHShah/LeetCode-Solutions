class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();

        // pre[i][c]: latest index of character c in s[0...i]
        // suf[i][c]: earliest index of character c in s[i...n-1]
        vector<vector<int>> pre(n, vector<int>(26, -1));
        vector<vector<int>> suf(n, vector<int>(26, n));

        // Fill pre table
        for (int i = 0; i < n; i++) {
            if (i > 0) pre[i] = pre[i - 1];
            pre[i][s[i] - 'a'] = i;
        }

        // Fill suf table
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n) suf[i] = suf[i + 1];
            suf[i][s[i] - 'a'] = i;
        }

        long long totalPairs = 0;

        // Try every possible split point 'm'
        for (int m = 0; m + 1 < n; m++) {
            int left = m, right = m + 1;
            vector<bool> seenLeft(26, false), seenRight(26, false);

            while (left >= 0 && right < n) {
                seenLeft[s[left] - 'a'] = true;
                seenRight[s[right] - 'a'] = true;
                
                // Find the furthest back index constrained by missing characters on the left
                int nextLeft = -1;
                for (int c = 0; c < 26; c++) {
                    if (!seenLeft[c]) {
                        nextLeft = max(nextLeft, pre[left][c]);
                    }
                }

                // Find the closest forward index constrained by missing characters on the right
                int nextRight = n;
                for (int c = 0; c < 26; c++) {
                    if (!seenRight[c]) {
                        nextRight = min(nextRight, suf[right][c]);
                    }
                }

                // Add combinations for the current segments
                totalPairs += 1LL * (left - nextLeft) * (nextRight - right);
                
                left = nextLeft;
                right = nextRight;
            }
        }

        return totalPairs;
    }
};