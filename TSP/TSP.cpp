#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Func that calculates the total distance of a route (Brute Force)
int calculateDistance(vector<vector<int>>& distMatrix, vector<int>& route)
{
    int totalDistance = 0;
    for (int i = 0; i < (int)route.size() - 1; i++)
    {
        if (distMatrix[route[i]][route[i + 1]] == INT_MAX) // Check for unreachable path
        {
            return INT_MAX; // Unreachable (stupidly high num)
        }
        totalDistance += distMatrix[route[i]][route[i + 1]];
    }
    // Check return path
    if (distMatrix[route[route.size() - 1]][route[0]] == INT_MAX) 
    {
        return INT_MAX;
    }
    totalDistance += distMatrix[route[route.size() - 1]][route[0]];
    return totalDistance;
}

int main()
{
    // INT_MAX = unreachable paths
    vector<vector<int>> distMatrix =
        {
        {0, 2, 2, INT_MAX, INT_MAX}, // A
        {2, 0, 3, 3, 1}, // B
        {2, 3, 0, 1, 3}, // C
        {INT_MAX, 3, 1, 0, 3}, // D
        {INT_MAX, 1, 3, 3, 0}  // E
        };

    vector<int> cities = {0, 1, 2, 3, 4}; // Cities represented by indices (A, B, C, D, E)
    vector<char> cityNames = {'A', 'B', 'C', 'D', 'E'};
    
    int minDistance = INT_MAX;
    vector<int> bestRoute;

    // Try every possible route by generating permutations
    do
    {
        int currentDistance = calculateDistance(distMatrix, cities);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            bestRoute = cities;
        }
    }
    while (next_permutation(cities.begin() + 1, cities.end())); // Fix the first city to reduce duplicate routes

    // Output the results
    cout << "Minimum distance: " << minDistance << '\n';
    cout << "Best route: ";
    for (int city : bestRoute)
    {
        cout << cityNames[city] << " ";
    }
    cout << cityNames[bestRoute[0]] << '\n'; // Return to the starting city

    return 0;
}
