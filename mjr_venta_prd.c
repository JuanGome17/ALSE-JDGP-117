#include <stdio.h>
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) {
        return 0;
    }
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int rep = 1; rep < pricesSize; rep++) {
        if (prices[rep] < minPrice) {
            minPrice = prices[rep];
        } else {
            int profit = prices[rep] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }
    return maxProfit;
}
int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]);

    printf("Max profit: %d\n", maxProfit(prices, size));
    return 0;
}