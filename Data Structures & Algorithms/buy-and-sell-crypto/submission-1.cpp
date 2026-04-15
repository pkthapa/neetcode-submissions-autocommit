class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_Profit = 0;
        int buyPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buyPrice) {
                buyPrice= prices[i];
                continue;
            }
            max_Profit = max(max_Profit, prices[i] - buyPrice);
        }
        return max_Profit;
    }
};
