class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        // Count number of occurrences
        for (auto& num : nums) {
            m[num]++;
        }

        // Create a vector to store and group numbers against the occurrence count
        // Since the input array size of 6, so any number from the input array
        // cannot be repeated more than 6, i.e. a number can be repeated a max of
        // 6 (equal to length of the input array) times only. Hence, creating an output
        // vector with 6 + 1 size and its offset represents occurrence count, i.e.
        // if 2 numbers are repeated 3 times each then those numbers will be grouped
        // under offset 3 of output array.
        vector<vector<int>> numGroup(nums.size() + 1, vector<int>());
        for (auto& x : m) {
            numGroup[x.second].push_back(x.first);
        }

        vector<int> output;
        // Scan the output array from the right (higher index) side
        for (int i = numGroup.size() - 1; i >= 0; i--) {
            if (numGroup[i].size() > 0) {
                auto arr = numGroup[i];
                for (auto& a : arr) {
                    output.push_back(a);
                    if (--k == 0) {
                        return output;
                    }
                }
            }
        }
        return {};
    }
};
