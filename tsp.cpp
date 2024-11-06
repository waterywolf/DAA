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

    cout << "All possible routes and their distances:\n";

    do
    {
        int currentDistance = calculateRouteDistance(cities, distanceMatrix);

        // Display the current route
        for (int city : cities)
        {
            cout << city << " ";
        }
        cout << " | Distance: " << currentDistance << endl;

        // Update minimum distance and best route if a shorter path is found
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            bestRoute = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    cout << "\nShortest route: ";
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
