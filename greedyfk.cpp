#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Greedy {
public:
    int id;
    float wt, pft, pw, amt;

    void calculateRatio() {
        pw = pft / wt;
    }
};

int main() {
    int n;
    float capacity, totalWeight = 0, totalProfit = 0;

    cout << "Enter total number of objects: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    vector<Greedy> items(n);

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        items[i].amt = 0; 

        cout << "Enter weight of object " << (i + 1) << ": ";
        cin >> items[i].wt;

        cout << "Enter profit of object " << (i + 1) << ": ";
        cin >> items[i].pft;

        items[i].calculateRatio();
    }

    sort(items.begin(), items.end(), [](const Greedy& a, const Greedy& b) {
        return a.pw > b.pw;
    });

    cout << "\nItems sorted by profit/weight ratio:\n";
    cout << "id\tweight\tprofit\tp/w\n";
    for (const auto& item : items) {
        cout << item.id << "\t" << item.wt << "\t" << item.pft << "\t" << fixed << setprecision(2) << item.pw << "\n";
    }

    cout << "\nKnapsack solution:\n";
    cout << "id\tamount\tweight\tprofit\tp/w\n";
    for (auto& item : items) {
        if (totalWeight < capacity) {
            if (item.wt <= (capacity - totalWeight)) {
                item.amt = 1;
                totalWeight += item.wt;
                totalProfit += item.pft;
            } else {
                item.amt = (capacity - totalWeight) / item.wt;
                totalWeight = capacity; 
                totalProfit += item.amt * item.pft;
                break; 
            }
        } else {
            break; 
        }
    }

    for (const auto& item : items) {
        cout << item.id << "\t" << fixed << setprecision(2) << item.amt << "\t" << item.wt << "\t" << item.pft << "\t" << item.pw << "\n";
    }
    cout << "Total Profit is: " << totalProfit << endl;

    return 0;
}
