class Solution {
public:
    /*
    Intuition: Why XOR and AND?
    -> a ^ b → gives sum without carry
        Example:
        1 ^ 1 = 0
        1 ^ 0 = 1

    -> a & b → gives carry
        Example:
        1 & 1 = 1 (carry generated)
        (a & b) << 1 → shift carry to correct position
    */
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;
            int carry = (a & b) << 1;

            a = sum;
            b = carry;
        }
        return a;
    }
};
