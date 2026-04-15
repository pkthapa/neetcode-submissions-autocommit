class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ i ^ nums[i];
        }
        return result;
    }
};

/*
Key XOR Properties
x ^ x = 0 — a number XORed with itself cancels out
x ^ 0 = x — a number XORed with zero survives

The Core Idea
We XOR every index (0...n-1) with every value in the array, starting with n.
This means every number from 0 to n appears twice — except the missing one,
which appears once. All pairs cancel to 0, leaving only the missing number.
*/