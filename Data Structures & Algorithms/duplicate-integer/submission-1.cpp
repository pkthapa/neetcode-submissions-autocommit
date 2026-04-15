class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int i = 0;
        int j = 1;

        sort(nums.begin(), nums.end());

        while (j < nums.size()) {
            if (nums[i++] == nums[j++]) {
                return true;
            }
        }
        return false;
    }
};