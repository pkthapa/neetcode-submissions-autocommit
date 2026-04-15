class Solution {
public:
    // Every number is built from a previous number + one extra bit
    // dp[i >> 1] takes to previous number
    // (i & 1) add the last extra bit to previous number to get next number
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        
        // Base case
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
