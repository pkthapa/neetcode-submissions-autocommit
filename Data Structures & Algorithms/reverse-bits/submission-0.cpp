class Solution {
public:
    /*
    💡 Key Idea
    We build the result bit by bit from right to left:

    1. Take the last bit of n
        → using n & 1
    2. Shift result left to make space
        → result << 1
    3. Add that extracted bit to result
    4. Move to next bit of n
        → n >> 1

    Repeat this 32 times.
    */
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {
            int lastBit = (n & 1); // Take the last bit on 'n'
            result <<= 1; // Shift 'result' left to make space
            result |= lastBit; // Add the extracted result
            n >>= 1; // Move to next bit of 'n'
        }
        return result;
    }
};
