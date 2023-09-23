#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 20000
#define INF 987654321

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

struct Node {
    int weight;
    int vertex;

    Node(int v, int w) : weight(w), vertex(v) {}

    bool operator<(const Node n) const {
        return this->weight > n.weight;
    }
};

int dist[MAX + 1];
int visited[MAX + 1];
priority_queue<Node> pq;
vector<pair<int, int >> edges[MAX + 1];

void dijkstra(int start_vertices) {
    dist[start_vertices] = 0;
    pq.push(Node(start_vertices, 0));

    while (!pq.empty()) {
        auto n = pq.top();
        pq.pop();
        visited[n.vertex] = 1;

        for (auto edge: edges[n.vertex]) {

            auto [v, w] = edge;

            if (visited[v]) {
                continue;
            }

            int new_dist = n.weight + w;
            if (dist[v] > new_dist) {
                dist[v] = new_dist;
                pq.push(Node(v, new_dist));
            }
        }
    }
}

int main() {
    FASTIO

    int order, size;
    int u, v, w;
    int start_vertices;
    cin >> order >> size >> start_vertices;
    FOR_N_M(1, size, i) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }

    FOR_N_M(1, MAX, i) {
        dist[i] = INF;
    }
    dijkstra(start_vertices);

    FOR_N_M(1, order, v) {
        if (dist[v] == INF) {
            PRT("INF")
        } else {
            PRT(dist[v])
        }
    }
}