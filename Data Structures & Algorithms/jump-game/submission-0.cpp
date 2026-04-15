class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goalPos = nums.size() - 1;
        int currPos = goalPos - 1;

        while (currPos >= 0) {
            if (currPos + nums[currPos] >= goalPos) {
                goalPos = currPos;
            }
            currPos--;
        }
        return (goalPos == 0) ? true : false;
    }
};
