class Solution {
public:
    // Greedy Approach
    int jump(vector<int>& nums) {
        int jumps = 0;
        int coverage = 0;
        int lastJumpMaxIdx = 0;

        if (nums.size() == 1) {
            return jumps;
        }

        for (int i = 0; i < nums.size(); i++) {
            coverage = max(coverage, i + nums[i]);

            if (i == lastJumpMaxIdx) {
                jumps++;
                lastJumpMaxIdx = coverage;

                if (lastJumpMaxIdx >= nums.size() - 1) {
                    return jumps;
                }
            }
        }
        return jumps;
    }
};
