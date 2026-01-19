#include <iostream>
#include <vector>
using namespace std;

// 0/1 Knapsack using Dynamic Programming (Bottom-Up)
int knapSack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // dp[i][w] = maximum value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] iteratively
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                // Option 1: include item i-1
                int includeItem = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                // Option 2: exclude item i-1
                int excludeItem = dp[i - 1][w];
                // Take max of both
                dp[i][w] = max(includeItem, excludeItem);
            } else {
                // Cannot include this item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Answer is in last cell
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter values (profits) of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxValue = knapSack(W, wt, val, n);
    cout << "Maximum value that can be obtained = " << maxValue << endl;

    return 0;
}
