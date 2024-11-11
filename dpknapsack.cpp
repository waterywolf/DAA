#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int id;
    int weight;
    int profit;
};

int knapsack_01(const vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].profit);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Knapsack solution (0/1 Knapsack):\n";
    cout << "id\tweight\tprofit\n";
    int total_profit = dp[n][capacity];
    int remaining_capacity = capacity;

    for (int i = n; i > 0; --i) {
        if (dp[i][remaining_capacity] != dp[i - 1][remaining_capacity]) {
            cout << items[i - 1].id << "\t"
                 << items[i - 1].weight << "\t"
                 << items[i - 1].profit << "\n";
            remaining_capacity -= items[i - 1].weight;
        }
    }

    cout << "Total Profit is: " << total_profit << endl;
    return total_profit;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        items[i].id = i + 1;
        cout << "Enter details for item " << items[i].id << ":\n";
        cout << "  Enter weight: ";
        cin >> items[i].weight;
        cout << "  Enter profit: ";
        cin >> items[i].profit;
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    knapsack_01(items, capacity);

    return 0;
}
