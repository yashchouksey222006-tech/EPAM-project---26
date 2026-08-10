#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int N, M, D;
    cin >> N >> M >> D;

    // Create adjacency list
    vector<vector<int> > graph(N + 1);

    // Read all roads
    for (int i = 0; i < M; i++) {

        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Distance of every city from City 1
    vector<int> distance(N + 1, -1);

    queue<int> q;

    // Start BFS from City 1
    distance[1] = 0;
    q.push(1);

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {

            // If city has not been visited
            if (distance[neighbor] == -1) {

                distance[neighbor] = distance[current] + 1;

                q.push(neighbor);
            }
        }
    }

    // Count cities whose distance is <= D
    int answer = 0;

    for (int i = 1; i <= N; i++) {

        if (distance[i] != -1 && distance[i] <= D) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}