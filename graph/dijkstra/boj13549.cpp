#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 100000
#define INF numeric_limits<long>::max()

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll n, m;

struct Node {
    int weight;
    int vertex;

    Node(int v, int w) : weight(w), vertex(v) {}

    bool operator<(const Node n) const {
        return this->weight > n.weight;
    }
};

ll dist[MAX + 1];
ll visited[MAX + 1];
priority_queue<Node> pq;

ll dijkstra(ll start_vertices, ll end_vertices) {

    FOR_N_M(0, MAX, i) {
        dist[i] = INF;
        visited[i] = 0;
    }

    pq.push(Node(start_vertices, 0));
    dist[start_vertices] = 0;

    while (!pq.empty()) {

        auto u = pq.top();
        pq.pop();
        visited[u.vertex] = 1;

        ll a = u.vertex + 1;
        ll b = u.vertex - 1;
        ll c = u.vertex * 2;
        if (0 <= a && a <= MAX && !visited[a]) {
            ll new_dist = u.weight + 1;
            if (dist[a] > new_dist) {
                dist[a] = new_dist;
                pq.push(Node(a, new_dist));
            }
        }

        if (0 <= b && b <= MAX && !visited[b]) {
            ll new_dist = u.weight + 1;
            if (dist[b] > new_dist) {
                dist[b] = new_dist;
                pq.push(Node(b, new_dist));
            }
        }

        if (0 <= c && c <= MAX && !visited[c]) {
            ll new_dist = u.weight;
            if (dist[c] > new_dist) {
                dist[c] = new_dist;
                pq.push(Node(c, new_dist));
            }
        }
    }

    if (dist[end_vertices] == INF) {
        return -1;
    } else {
        return dist[end_vertices];
    }
}

int main() {
    FASTIO

    ll a, b;
    cin >> a >> b;

    PRT(dijkstra(a, b));
}