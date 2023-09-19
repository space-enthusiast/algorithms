#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 100
#define INF numeric_limits<long>::max()

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

ll game[MAX + 1];
vector<ll> graph[MAX + 1];

ll d[] = {1, 2, 3, 4, 5, 6};

int main() {
    FASTIO

    cin >> n >> m;

    ll a, b;
    FOR_N_M(1, n + m, i) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    FOR_N_M(1, 100, i) { game[i] = -1; }

    deque<ll> dq;
    dq.push_back(1);
    game[1] = 0;
    while (!dq.empty()) {

        ll u = dq.front();
        dq.pop_front();

        for (auto x: d) {
            ll v;
            v = u + x;
            if (graph[v].size() == 1) {
                v = graph[v][0];
            }
            if (!(1 <= v && v <= 100)) {
                continue;
            }
            if (game[v] != -1) {
                continue;
            }
            dq.push_back(v);
            game[v] = game[u] + 1;
        }
    }

    cout << game[100];
}