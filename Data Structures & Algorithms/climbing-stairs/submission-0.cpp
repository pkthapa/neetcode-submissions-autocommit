class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return n;
        }

        int n1 = 1; // No of ways to reach step 1
        int n2 = 2; // No of ways to reach step 2
        int totalWays = n2;

        for (int i = 2; i < n; i++) {
            totalWays = n1 + n2;

            n1 = n2;
            n2 = totalWays;
        }
        return totalWays;
    }
};
