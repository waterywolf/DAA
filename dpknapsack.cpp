#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>

using namespace std;
struct Item {

    int id;
    int weight;
    int profit;
    double pw_ratio;

};

int knapsack_fractional(const vector<Item>& items, int capacity) {

    double total_profit = 0.0;
    int remaining_capacity = capacity;

 cout << "Knapsack solution:\n";
 cout << "id\tamount\tweight\tprofit\tp/w\n";

    for (const auto& item : items) {
        if (remaining_capacity == 0) break;



        double amount = 0.0;
        if (item.weight <= remaining_capacity) {

            amount = 1.0; // Take the whole item
             remaining_capacity -= item.weight;
            total_profit += item.profit;

        } else {

            amount = static_cast<double>(remaining_capacity) / item.weight; // Take fraction of item
            total_profit += item.profit * amount;
            remaining_capacity = 0;

        }

        cout << item.id << "\t" 

             << fixed << setprecision(2) << amount << "\t"
             << item.weight << "\t"
             << item.profit << "\t"
             << fixed << setprecision(2) << item.pw_ratio << "\n";

    }

    cout << "Total Profit is: " << fixed << setprecision(2) << total_profit << endl;
    return total_profit;

}

int main() {

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {

        items[i].id = i + 1;  // Automatically assign id
        cout << "Enter details for item " << items[i].id << ":\n";
        cout << "  Enter weight: ";
        cin >> items[i].weight;
        cout << "  Enter profit: ";
        cin >> items[i].profit;

        items[i].pw_ratio = static_cast<double>(items[i].profit) / items[i].weight;
    }
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
    return a.pw_ratio > b.pw_ratio;

    });
    knapsack_fractional(items, capacity);



    return 0;

}

