class Solution {
    int helper(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int rob1 = helper(nums, 0, nums.size() - 2);
        int rob2 = helper(nums, 1, nums.size() - 1);

        return max(rob1, rob2);
    }
};
