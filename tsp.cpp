#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int calculateRouteDistance(const vector<int> &route, const vector<vector<int>> &distanceMatrix)
{
    int totalDistance = 0;
    int n = route.size();
    for (int i = 0; i < n; i++)
    {
        totalDistance += distanceMatrix[route[i]][route[(i + 1) % n]];
    }
    return totalDistance;
}

void travelingSalesman(const vector<vector<int>> &distanceMatrix)
{
    int n = distanceMatrix.size();
    vector<int> cities(n);
    for (int i = 0; i < n; i++)
    {
        cities[i] = i;
    }

    int minDistance = numeric_limits<int>::max();
    vector<int> bestRoute;
    do
    {
        int currentDistance = calculateRouteDistance(cities, distanceMatrix);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            bestRoute = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));
    cout << "Shortest route: ";
    for (int city : bestRoute)
    {
        cout << city << " ";
    }
    cout << "\nMinimum distance: " << minDistance << endl;
}

int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> distanceMatrix(n, vector<int>(n));

    cout << "Enter the distance matrix (enter 0 for diagonal elements):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> distanceMatrix[i][j];
        }
    }

    travelingSalesman(distanceMatrix);
    return 0;
}
