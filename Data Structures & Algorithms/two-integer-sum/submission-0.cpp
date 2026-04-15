class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            auto itr = m.find(diff);
            if (itr != m.end()) {
                return {itr->second, i};
            }
            else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};
