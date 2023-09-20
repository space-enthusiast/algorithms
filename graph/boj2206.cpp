#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 1000
#define INF numeric_limits<long>::max()

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

pair<int, int> d[] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1},
};

int main() {
    FASTIO

    cin >> n >> m;

    int maze[MAX + 1][MAX + 1];
    int solve[MAX + 1][MAX + 1][2];

    FOR_N_M(1, MAX, i) { FOR_N_M(1, MAX, j) { FOR_N_M(0, 1, k) { solve[i][j][k] = -1; }}}

    string temp;
    FOR_N_M(1, n, i) {
        cin >> temp;
        FOR_N_M(0, temp.size() - 1, j) {
            maze[i][j + 1] = temp[j] == '0' ? 0 : 1;
        }
    }

    deque<pair<pair<int, int>, int>> dq;
    dq.push_back({{1, 1}, 0});
    solve[1][1][0] = 1;

    while (!dq.empty()) {

        auto [ui, uj] = dq.front().first;
        int wall = dq.front().second;
        dq.pop_front();

        if (ui == n && uj == m) {
            cout << solve[ui][uj][wall];
            return 0;
        }

        for (auto [dx, dy]: d) {
            int vi = ui + dx;
            int vj = uj + dy;

            if (!(1 <= vi && vi <= n && 1 <= vj && vj <= m)) {
                continue;
            }

            if (maze[vi][vj] == 0 && solve[vi][vj][wall] == -1) {
                solve[vi][vj][wall] = solve[ui][uj][wall] + 1;
                dq.push_back({{vi, vj}, wall});
            } else if (wall == 0 && maze[vi][vj] == 1 && solve[vi][vj][1] == -1) {
                solve[vi][vj][1] = solve[ui][uj][0] + 1;
                dq.push_back({{vi, vj}, 1});
            }
        }
    }

    cout << -1;
}