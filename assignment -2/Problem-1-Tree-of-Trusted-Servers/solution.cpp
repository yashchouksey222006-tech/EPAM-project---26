#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

int main() {

    int N;
    long long K;

    cin >> N >> K;

    vector<long long> key(N + 1);

    // Read security keys
    for (int i = 1; i <= N; i++) {
        cin >> key[i];
    }

    // Create tree
    vector<vector<int> > tree(N + 1);

    // Read edges
    for (int i = 0; i < N - 1; i++) {

        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int trusted = 0;

    // Stack stores:
    // node, parent, XOR from root to node
    stack< tuple<int, int, long long> > st;

    // Start from root (Server 1)
    st.push(make_tuple(1, 0, key[1]));

    while (!st.empty()) {

        tuple<int, int, long long> current = st.top();
        st.pop();

        int node = get<0>(current);
        int parent = get<1>(current);
        long long pathXOR = get<2>(current);

        // Check whether server is trusted
        if (pathXOR >= K) {
            trusted++;
        }

        // Visit all connected servers
        for (int child : tree[node]) {

            if (child == parent) {
                continue;
            }

            long long childXOR = pathXOR ^ key[child];

            st.push(make_tuple(child, node, childXOR));
        }
    }

    cout << trusted << endl;

    return 0;
}