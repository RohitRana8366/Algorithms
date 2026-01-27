#include <iostream>
using namespace std;

#define INF 999999   // A large value representing "infinity"

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int dist[20][20];

    cout << "Enter adjacency matrix (use 0 if no edge and i!=j):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
            if (i != j && dist[i][j] == 0) {
                dist[i][j] = INF;  // no direct edge
            }
        }
    }

    // Floyd–Warshall Algorithm
    for (int k = 0; k < V; k++) {          // intermediate vertex
        for (int i = 0; i < V; i++) {      // source
            for (int j = 0; j < V; j++) {  // destination
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest path matrix
    cout << "\nAll Pair Shortest Path Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
