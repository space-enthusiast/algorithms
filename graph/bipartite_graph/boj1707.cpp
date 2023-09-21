#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 200000
#define INF numeric_limits<long>::max()

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

vector<int> E[200000 + 1];
int solve[20000 + 1];
deque<int> dq;

bool bfs(int r) {
    dq.push_back(r);
    if (solve[r] == 0) {
        solve[r] = 1;
    }

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        int s = solve[u];

        for (auto v: E[u]) {
            if (solve[v] == s) {
                return false;
            }

            if (solve[v] == 0) {
                solve[v] = -s;
                dq.push_back(v);
            }
        }
    }

    return true;
}

int main() {
    FASTIO

    ll t;
    cin >> t;
    while (t--) {

        ll e, a, b;
        cin >> n >> e;

        FOR_N_M(1, 200000, i) { E[i].clear(); }

        FOR_N_M(1, e, i) {
            cin >> a >> b;
            E[a].push_back(b);
            E[b].push_back(a);
        }

        FOR_N_M(1, 20000, i) { solve[i] = 0; }

        bool isBipartite = true;
        FOR_N_M(1, n, v) {
            dq.clear();
            if (!bfs(v)) {
                isBipartite = false;
                break;
            }
        }

        if (isBipartite) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

/*
1
3 2
1 3
2 3

YES


1
4 4
1 2
2 3
3 4
4 2

NO
*/