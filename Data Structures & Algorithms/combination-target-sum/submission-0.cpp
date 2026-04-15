class Solution {
    void helper(int idx, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp) {
        if (idx == nums.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if (nums[idx] <= target) {
            temp.push_back(nums[idx]);
            helper(idx, nums, target - nums[idx], ans, temp);
            temp.pop_back();
        }

        helper(idx + 1, nums, target, ans, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, nums, target, ans, temp);
        return ans;
    }
};
