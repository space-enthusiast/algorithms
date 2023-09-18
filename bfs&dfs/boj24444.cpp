#define FOR_N(N, I) for(long long int I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(long long int I=N;I<=M;I++)
#define PRT_SET(SET) for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_SET_NAME(SET_NAME, SET) cout<<SET_NAME<<": "; for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ARY_1D(ARR, N) for(long long int PRT_ARY_1D_IDX=0;PRT_ARY_1D_IDX<N;PRT_ARY_1D_IDX++){ cout<<ARR[PRT_ARY_1D_IDX]<<' '; } cout<<"\n";
#define PRT_ARY_2D(ARR, N, M) for(long long int PRT_ARY_2D_I=0;PRT_ARY_2D_I<N;PRT_ARY_2D_I++){ for(long long int PRT_ARY_2D_J=0;PRT_ARY_2D_J<M;PRT_ARY_2D_J++) { cout<<ARR[PRT_ARY_2D_I][PRT_ARY_2D_J]<<' '; } cout<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define LAST_IDX(N) (N-1)
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define NOT !
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();
#define MAX 1000000
#define INF numeric_limits<long>::max()
#define INI_ARR_NUM(ARR, N) long long int ARR[N]; memset(ARR, 0, sizeof(ARR));
#define INI_ARR_VAL(ARR, N, INI_VAL) long long int (ARR)[(N)]; for (long long int i = 0; i < (N); i++) {(ARR)[i] = (INI_VAL); }
#define SIEVE_OF_ERATOSTHENE(ARR, N) long long int (ARR)[(N+1)]; (ARR)[1]=0; for (long long int SOE_IDX = 1;SOE_IDX<=N;SOE_IDX++) (ARR)[SOE_IDX] = 1; long long int SOR_SQRT_N = sqrt(N); for (long long int SOE_IDX = 2; SOE_IDX < SOR_SQRT_N; SOE_IDX++) { long long int SOE_TIMES = 2; if (ARR[SOE_IDX] == 0) continue; while (SOE_IDX * SOE_TIMES <= N) { (ARR)[SOE_IDX * SOE_TIMES] = 0; SOE_TIMES++; }}
#define EXIST(EXIST_ITER, N) EXIST_ITER.find(N) != EXIST_ITER.end()

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;
ll cnt;
deque<ll> dq;
vector<ll> graph[MAX + 1];
ll visited[MAX + 1];
ll res[MAX + 1];

void bfs(ll r) {
    visited[r] = 1;
    res[r] = ++cnt;
    dq.push_back(r);
    while (NOT dq.empty()) {
        ll u = dq.front();
        dq.pop_front();
        for (ll v: graph[u]) {
            if (NOT visited[v]) {
                visited[v] = 1;
                res[v] = ++cnt;
                dq.push_back(v);
            }
        }
    }
}

int main() {
    FASTIO

    ll r, a, b;
    cin >> n >> m >> r;
    FOR_N(m, i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    FOR_N_M(1, n, i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(r);

    FOR_N_M(1, n, i) {
        PRT(res[i])
    }
}