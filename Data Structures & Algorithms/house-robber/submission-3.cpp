class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        // int dp[nums.size()];

        // int prev2 = nums[0]; // dp[0] = nums[0];
        // int prev1 = max(nums[0], nums[1]); // dp[1] = max(nums[0], nums[1]);

        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < nums.size(); i++) {
            // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
