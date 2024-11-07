#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class TSP {
private:
    int n;
    vector<vector<int>> cost_matrix;
    vector<int> final_path;
    int final_res;

public:
    TSP(const vector<vector<int>>& cost) : cost_matrix(cost) {
        n = cost_matrix.size();
        final_res = INT_MAX;
        final_path.resize(n + 1);
    }

    void travelling_salesman() {
        vector<bool> visited(n, false);
        visited[0] = true;
        vector<int> path;
        path.push_back(0);
        int cost = reduce_matrix();
        travelling_salesman_util(0, 1, cost, visited, path);
    }

    void travelling_salesman_util(int curr_pos, int count, int cost, vector<bool>& visited, vector<int>& path) {
        if (count == n) {
            if (cost_matrix[curr_pos][0]) {
                int total_cost = cost + cost_matrix[curr_pos][0];
                if (total_cost < final_res) {
                    final_path = path;
                    final_path.push_back(0);
                    final_res = total_cost;
                }
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i] && cost_matrix[curr_pos][i]) {
                int temp = cost_matrix[curr_pos][i];
                cost += temp;
                visited[i] = true;
                path.push_back(i);
                travelling_salesman_util(i, count + 1, cost, visited, path);
                visited[i] = false;
                path.pop_back();
                cost -= temp;
            }
        }
    }

    int reduce_matrix() {
        int total_reduction = 0;

        for (int i = 0; i < n; i++) {
            int row_min = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (cost_matrix[i][j] < row_min && cost_matrix[i][j] != 0) {
                    row_min = cost_matrix[i][j];
                }
            }
            if (row_min != INT_MAX) {
                total_reduction += row_min;
                for (int j = 0; j < n; j++) {
                    cost_matrix[i][j] -= row_min;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            int col_min = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (cost_matrix[i][j] < col_min && cost_matrix[i][j] != 0) {
                    col_min = cost_matrix[i][j];
                }
            }
            if (col_min != INT_MAX) {
                total_reduction += col_min;
                for (int i = 0; i < n; i++) {
                    cost_matrix[i][j] -= col_min;
                }
            }
        }

        return total_reduction;
    }

    void print_result() {
        cout << "Minimum cost: " << final_res << endl;
        cout << "Path: ";
        for (size_t i = 0; i < final_path.size(); ++i) {
            cout << final_path[i] + 1;
            if (i < final_path.size() - 1) {
                cout << " → ";
            }
        }
        cout << endl;
    }
};

int main() {
    int num_cities;
    cout << "Enter the number of cities: ";
    cin >> num_cities;

    vector<vector<int>> cost_matrix(num_cities, vector<int>(num_cities));

    cout << "Enter the cost matrix (enter 0 for no direct path):\n";
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_cities; j++) {
            cin >> cost_matrix[i][j];
        }
    }

    TSP tsp(cost_matrix);
    tsp.travelling_salesman();
    tsp.print_result();

    return 0;
}
