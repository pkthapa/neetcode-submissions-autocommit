class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int maxProfit = 0;

        while (sell < prices.size()) {
            if (prices[buy] < prices[sell]) {
                maxProfit = max(maxProfit, prices[sell] - prices[buy]);
            }
            else {
                buy = sell;
            }
            sell++;
        }
        return maxProfit;
    }
};
