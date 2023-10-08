#define FOR(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 200000
#define MOD 10000000007
#define INF numeric_limits<long>::max()

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<pair<ll, ll>, ll> iii;

vector<ll> E[MAX + 1];
ll visited[MAX + 1];
ll depth_cnt[MAX + 1];
queue<ii> q;

void solve(ll node, ll node_depth) {

    visited[node] = 1;
    depth_cnt[node_depth]++;
    q.emplace(node, node_depth);

    while (!q.empty()) {

        auto [current_node, current_node_depth] = q.front();
        q.pop();

        ll next_node_depth = current_node_depth + 1;

        for (auto next_node: E[current_node]) {
            if (!visited[next_node]) {
                visited[next_node] = 1;
                depth_cnt[next_node_depth]++;
                q.emplace(next_node, next_node_depth);
            }
        }
    }
}

int main() {
    FASTIO

    ll n, m;
    ll ta, tb;

    cin >> n >> m;
    FOR(1, m, i) {
        cin >> ta >> tb;
        E[ta].push_back(tb);
        E[tb].push_back(ta);
    }

    solve(1, 1);

    ll sum = depth_cnt[1] + 1;
    FOR(2, MAX, i) {
        if (depth_cnt[i] == 0) {
            break;
        }
        sum *= (depth_cnt[i] + 1);
        sum %= MOD;
    }

    cout << sum - 1;
}