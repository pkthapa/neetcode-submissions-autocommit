class Solution {
    void backtrack(int idx, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& result) {
        // ✅ Found valid combination
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        // ❌ Out of bounds or exceeded target
        if (idx >= nums.size() || target < 0) {
            return;
        }

        // -------------------------
        // Choice 1: Take current number
        // -------------------------
        curr.push_back(nums[idx]);
        backtrack(idx, nums, target - nums[idx], curr, result);
        curr.pop_back();

        // -------------------------
        // Choice 2: Skip current number
        // -------------------------
        backtrack(idx + 1, nums, target, curr, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        backtrack(0, nums, target, curr, result);

        return result;
    }
};
