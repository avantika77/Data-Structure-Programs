#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Structure representing each city
struct City {
    int x;
    int y;
};

// Function to calculate the Euclidean distance between two cities
double distance(const City& city1, const City& city2) {
    int dx = city1.x - city2.x;
    int dy = city1.y - city2.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to solve the TSP using a greedy algorithm
// Returns the length of the tour
double tspGreedy(const vector<City>& cities) {
    int n = cities.size();
    vector<bool> visited(n, false); // Mark all cities as unvisited
    visited[0] = true; // Start from the first city
    double totalDistance = 0.0; // Initialize total distance

    // Start from the first city
    int currentCity = 0;

    // Visit each city exactly once
    for (int i = 1; i < n; ++i) {
        int nextCity = -1;
        double minDistance = numeric_limits<double>::max(); // Initialize minimum distance to a large value

        // Find the nearest unvisited city
        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                double d = distance(cities[currentCity], cities[j]);
                if (d < minDistance) {
                    minDistance = d;
                    nextCity = j;
                }
            }
        }

        // Move to the nearest unvisited city
        visited[nextCity] = true;
        totalDistance += minDistance;
        currentCity = nextCity;
    } 
    

    // Return to the starting city
    totalDistance += distance(cities[currentCity], cities[0]);

    return totalDistance;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<City> cities(n);

    // Input city coordinates from the user
    cout << "Enter the coordinates (x y) for each city:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "City " << i + 1 << ": ";
        cin >> cities[i].x >> cities[i].y;
    }

    double tourLength = tspGreedy(cities);

    cout << "Length of the tour using greedy algorithm: " << tourLength << endl;

    return 0;
}
