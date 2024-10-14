#include <iostream>
#include <vector>
using namespace std;

int knapsack_01(const vector<int>& values, const vector<int>& weights, int capacity, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the value of item " << i + 1 << ": ";
        cin >> values[i];
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> weights[i];
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int max_value = knapsack_01(values, weights, capacity, n);
    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}
