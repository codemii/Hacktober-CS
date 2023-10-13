#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int> weights, vector<int> values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 10; // Knapsack capacity
    vector<int> weights = {2, 3, 4, 5}; // Item weights
    vector<int> values = {3, 4, 5, 6};  // Item values

    int max_value = knapsack(W, weights, values);

    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
