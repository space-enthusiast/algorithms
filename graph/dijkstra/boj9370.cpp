#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 2000
#define INF numeric_limits<long>::max()

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<pair<ll, ll>, ll> iii;

struct Node {
    ll vertices;
    ll weight;

    Node(int v, int w) : weight(w), vertices(v) {}

    bool operator<(const Node n) const {
        return this->weight > n.weight;
    }
};

void dijkstra(ll start_vertices, ll start_vertices_dist, ll *dist, ll *visited, vector<ii> edges[MAX + 1]) {

    priority_queue<Node> pq;

    FOR_N_M(1, MAX, i) {
        visited[i] = 0;
        dist[i] = INF;
    }

    if (start_vertices_dist == INF) {
        return;
    }

    dist[start_vertices] = start_vertices_dist;
    pq.push(Node(start_vertices, dist[start_vertices]));

    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        visited[u.vertices] = 1;

        for (auto edge: edges[u.vertices]) {

            auto [v, w] = edge;

            if (visited[v]) {
                continue;
            }

            ll new_dist = u.weight + w;
            if (dist[v] > new_dist) {
                dist[v] = new_dist;
                pq.emplace(v, new_dist);
            }
        }
    }
}

void solve() {
    ll t, order, size;
    ll start, g, h;
    ll u, v, w;
    ll tmp;
    vector<ll> destinations;
    vector<ii> ans_real;
    vector<ii> ans_mid;

    ll dist[MAX + 1];
    ll visited[MAX + 1];
    vector<ii> edges[MAX + 1];
    for (auto edge: edges) {
        edge.clear();
    }

    cin >> order >> size >> t;
    cin >> start >> g >> h;

    ll g_h_dist;
    FOR_N_M(1, size, i) {
        cin >> u >> v >> w;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
        if ((u == g && v == h) || (v == g && u == h)) {
            g_h_dist = w;
        }
    }
    FOR_N_M(1, t, i) {
        cin >> tmp;
        destinations.push_back(tmp);
    }
    sort(destinations.begin(), destinations.end());

    dijkstra(start, 0, dist, visited, edges);

    ii start_g_h = pair(h, dist[g] + g_h_dist);
    ii start_h_g = pair(g, dist[h] + g_h_dist);

    for (auto des: destinations) {
        ans_real.emplace_back(des, dist[des]);
    }

    ii mid_node = start_g_h.second < start_h_g.second ? start_g_h : start_h_g;

    dijkstra(mid_node.first, mid_node.second, dist, visited, edges);

    for (auto des: destinations) {
        ans_mid.emplace_back(des, dist[des]);
    }

    dijkstra(start, 0, dist, visited, edges);

    for (auto des: destinations) {
        ans_mid.emplace_back(des, dist[des]);
    }

    for (auto des: destinations) {
        ans_mid.emplace_back(des, dist[des]);
    }
    FOR_N_M(0, destinations.size() - 1, i) {
        if (ans_real[i].second != INF && ans_real[i].second == ans_mid[i].second) {
            cout << destinations[i] << ' ';
//            PRT_NAME("ans", destinations[i])
        }
    }
}

int main() {
    FASTIO

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}

/*
예제 1 - 통과
1
6 9 2
2 3 1
1 2 1
1 3 3
2 4 4
2 5 5
3 4 3
3 6 2
4 5 4
4 6 3
5 6 7
5
6

6


예제 2 - 통과
1
5 4 2
1 2 3
1 2 6
2 3 2
3 4 4
3 5 3
5
4

4 5


예제 3 - 미통과
2
5 4 2
1 2 3
1 2 6
2 3 2
3 4 4
3 5 3
5
4
6 9 2
2 3 1
1 2 1
1 3 3
2 4 4
2 5 5
3 4 3
3 6 2
4 5 4
4 6 3
5 6 7
5
6

4 5
6
 */