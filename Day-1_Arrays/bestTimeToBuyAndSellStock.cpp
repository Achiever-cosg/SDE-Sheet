// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;

        int maxProfit = 0;
        int costPrice = prices[0];

        for(int x: prices)
        {
            maxProfit = max(maxProfit, x - costPrice);
            if(x < costPrice)
                costPrice = x;
        }

        return maxProfit;
    }
};