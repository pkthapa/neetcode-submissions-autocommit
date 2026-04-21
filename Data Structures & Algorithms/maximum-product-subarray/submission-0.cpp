class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            // When curr < 0:
            // maxPrev and minPrev roles swap automatically.
            if (curr < 0) {
                swap(maxProd, minProd);
            }
            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            result = max(result, maxProd);
        }
        return result;
    }
};
