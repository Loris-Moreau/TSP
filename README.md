﻿# Explanation of the code

This code implements a brute-force solution to the Traveling Salesman Problem (TSP) for five cities.

The goal is to find the shortest round-trip route that visits each city exactly once and returns to the starting point. Here’s the explanation:


1. Modelize Cities + Roads with distances
2. Find the best way to start from a city, go through all the cities and go back to the start


### Key Parts of the Code
1. Distance Matrix (`distMatrix`):

* A `vector<vector<int>>` matrix represents distances between each pair of cities. For example, `distMatrix[0][1]` is the distance from city **_A_** to city ***B***.

* `INT_MAX` represents an unreachable path between two cities, making the route invalid if it includes that segment.


2. Route Representation:
* Cities are indexed (***0*** for ***A***, ***1*** for ***B***, etc.), and the route is stored as a `vector<int>`.

* `cityNames` vector maps city indices to names for more readable output.


3. `calculateDistance` Function:
* This function calculates the total distance of a route, ensuring that every leg of the route is reachable.

* **The function takes** :
  * `distMatrix` : the distance matrix for city pairs.
  * `route` : the tested route, represented as a sequence of city indices.

* **How It Works**:
  * ***Loop through Route*** : The distance between each pair of consecutive cities in the route is added to the total distance.
  * ***Unreachable Path Check*** : If any distance is `INT_MAX`, the function immediately returns `INT_MAX`, marking the route as *unreachable*.
  * ***Return to Start Check*** : After looping through all pairs in the route, the distance from the last city is added back to the starting city. If this distance is also `INT_MAX`, the route is *unreachable*.

* The function returns the total distance for the route if valid, or INT_MAX if any segment is unreachable.


4. Main Algorithm (Main Function):
* **Initialization** :
  * `distMatrix` defines distances between cities.
  * `cities` hold indices representing each city.
  * `cityNames` is used to translate city indices to names for output.
  * `minDistance` is initialized to `INT_MAX` to track the minimum distance found.
  * `bestRoute` stores the optimal route.

* **Generating Permutations** :
  * The program generates all possible routes by permutating `cities` (except the first city, which is fixed for optimization).

  * Route Evaluation:
    * For each permutation of cities, `calculateDistance()` computes the route's total distance.
    * If the distance is smaller than `minDistance`, the route and its distance become the new `bestRoute` and `minDistance`.

* **Output** :
  * After evaluating all permutations, the program prints the minimum distance and the optimal route (in terms of city names).


5. Additional Notes
* `next_permutation` :
  * This function generates the next lexicographical permutation of the `cities` vector, enabling a brute-force approach to try all possible city sequences.
  * Fixing the first city (using `cities.begin() + 1`) avoids duplicate routes that differ only in starting points.
* **Efficiency** :
  * This brute-force approach has factorial time complexity, so it only works efficiently with a small number of cities.
  * For more than 5-10 cities, more advanced algorithms like dynamic programming or heuristic methods are needed.
