#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 1000000
#define INF numeric_limits<long>::max()

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

pair<ll, ll> d[] = {
        {1, 2},
        {2, 1},
        {-1, -2},
        {-2, -1},
        {1, -2},
        {-1, 2},
        {-2, 1},
        {2, -1},
};

int main() {
    FASTIO

    ll t;
    cin >> t;
    while (t--) {

        ll l;
        ll si, sj, ti, tj;
        cin >> l;
        cin >> si >> sj >> ti >> tj;


        ll chess[l][l];
        FOR_N_M(0, l - 1, i) { FOR_N_M(0, l - 1, j) { chess[i][j] = -1; }}

        deque<pair<ll, ll>> dq;
        dq.push_back({si, sj});
        chess[si][sj] = 0;

        while (!dq.empty()) {
            auto [ui, uj] = dq.front();
            dq.pop_front();

            for (auto dxy: d) {
                auto [dx, dy] = dxy;
                ll ci = ui + dx;
                ll cj = uj + dy;
                if (!(0 <= ci && ci < l && 0 <= cj && cj < l)) {
                    continue;
                }
                if (chess[ci][cj] != -1) {
                    continue;
                }
                dq.push_back({ci, cj});
                chess[ci][cj] = chess[ui][uj] + 1;
            }
        }

        cout << chess[ti][tj] << '\n';
    }
}