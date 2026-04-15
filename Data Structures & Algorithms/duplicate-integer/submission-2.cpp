class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (const auto& num : nums) {
            if (s.count(num) > 0) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};