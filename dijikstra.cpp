#include <iostream>
using namespace std;

#define INF 999999  // A very large value representing infinity

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm
void dijkstra(int graph[10][10], int V, int src) {
    int dist[10];      // dist[i] will hold the shortest distance from src to i
    bool visited[10];  // visited[i] is true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visited, V);

        visited[u] = true; // Mark the picked vertex as processed

        // Update dist[v] only if:
        // 1) v is not visited
        // 2) there is an edge from u to v (graph[u][v] != 0)
        // 3) dist[u] is not INF
        // 4) dist[u] + graph[u][v] is smaller than current dist[v]
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    cout << "\nVertex\tDistance from Source (" << src << ")\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices (max 10): ";
    cin >> V;

    int graph[10][10];

    cout << "Enter adjacency matrix (enter 0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int src;
    cout << "Enter source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    dijkstra(graph, V, src);

    return 0;
}
