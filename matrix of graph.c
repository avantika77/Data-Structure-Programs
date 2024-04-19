#include <stdio.h>
#include <limits.h>

#define N 2

int graph[N][N];
int visited[N];
int min_cost = INT_MAX;

void tsp_branch_and_bound(int current_city, int depth, int cost) {
    if (depth == N) {
        // Return to the starting city
        cost += graph[current_city][0];
        if (cost < min_cost)
            min_cost = cost;
        return;
    }

    visited[current_city] = 1;

    for (int next_city = 0; next_city < N; next_city++) {
        if (!visited[next_city] && graph[current_city][next_city] != 0 &&
            cost + graph[current_city][next_city] < min_cost) {
            tsp_branch_and_bound(next_city, depth + 1, cost + graph[current_city][next_city]);
        }
    }

    visited[current_city] = 0;
}

int main() {
    printf("Enter the adjacency matrix for the graph (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    tsp_branch_and_bound(0, 1, 0);
    printf("Optimal Cost: %d\n", min_cost);
    return 0;
}

