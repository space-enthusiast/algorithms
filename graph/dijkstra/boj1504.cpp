#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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

int dist[800 + 1];
int visited[800 + 1];
priority_queue<Node> pq;
vector<pair<int, int >> edges[200000 + 1];

int dijkstra(int start_vertices, int end_vertices) {
    FOR_N_M(1, 800, i) {
        dist[i] = INF;
        visited[i] = 0;
    }

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

    return dist[end_vertices];
}

int main() {
    FASTIO

    int v1, v2;
    int order, size;
    int u, v, w;
    cin >> order >> size;
    FOR_N_M(1, size, i) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    cin >> v1 >> v2;


    bool dist_v1_v2_possible = true;
    int dist_v1_v2 = 0;

    int one_v1 = dijkstra(1, v1);
    if (one_v1 == INF) {
        dist_v1_v2_possible = false;
    } else {
        dist_v1_v2 += one_v1;
    }

    int v1_v2 = dijkstra(v1, v2);
    if (v1_v2 == INF) {
        dist_v1_v2_possible = false;
    } else {
        dist_v1_v2 += v1_v2;
    }

    int v2_end = dijkstra(v2, order);
    if (v2_end == INF) {
        dist_v1_v2_possible = false;
    } else {
        dist_v1_v2 += v2_end;
    }


    bool dist_v2_v1_possible = true;
    int dist_v2_v1 = 0;

    int one_v2 = dijkstra(1, v2);
    if (one_v2 == INF) {
        dist_v2_v1_possible = false;
    } else {
        dist_v2_v1 += one_v2;
    }

    int v2_v1 = dijkstra(v2, v1);
    if (v2_v1 == INF) {
        dist_v2_v1_possible = false;
    } else {
        dist_v2_v1 += v2_v1;
    }

    int v1_end = dijkstra(v1, order);
    if (v1_end == INF) {
        dist_v2_v1_possible = false;
    } else {
        dist_v2_v1 += v1_end;
    }

    if (dist_v1_v2_possible && dist_v2_v1_possible) {
        if (dist_v1_v2 > dist_v2_v1) {
            PRT(dist_v2_v1)
//            PRT_NAME("1: ", dist_v2_v1)
        } else {
            PRT(dist_v1_v2)
//            PRT_NAME("2: ", dist_v1_v2)
        }
    } else if (dist_v1_v2_possible) {
        PRT(dist_v1_v2)
//        PRT_NAME("3: ", dist_v1_v2)
    } else if (dist_v2_v1_possible) {
        PRT(dist_v2_v1)
//        PRT_NAME("4: ", dist_v2_v1)
    } else {
        PRT(-1)
//        PRT_NAME("5: ", -1)
    }
}