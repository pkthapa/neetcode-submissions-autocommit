class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;

        for (auto& num : nums) {
            hashSet.insert(num);
        }

        int output = 0;
        for (auto& num : hashSet) {
            int temp = 0;
            int start = 0;

            if (hashSet.count(num - 1) == 0) {
                start = num;
                temp++;
                
                while (hashSet.count(++start) > 0) {
                    temp++;
                }
                output = max(output, temp);
            }
        }
        return output;
    }
};
