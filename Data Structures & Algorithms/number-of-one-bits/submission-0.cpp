class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        // n     = 3 (0000 0011)
        // n - 1 = 2 (0000 0010)
        // (n - 1) always clears the lowest bit
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};
