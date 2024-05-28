#include <cstdio>
#include <vector>
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int profit = 0;
    int buy_index = 0;
    int sell_index = 1;

    int current_profit = 0;
    while (sell_index < prices.size()) {
      current_profit = prices[sell_index] - prices[buy_index];

      if (current_profit > profit) {
        profit = current_profit;
      }

      if (current_profit < 0) {
        buy_index = sell_index;
      }

      sell_index++;
    }

    return profit;
  }
};

int main() {
  std::vector<int> prices = {1, 2};
  Solution *soln = new Solution();
  int res = soln->maxProfit(prices);
  printf("result: %d", res);
}
