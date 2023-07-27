#define FOR_N_INP(I) int N; cin>>N; for(I=0;I<N;I++)
#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT(A) cout<<(A);
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { cout<<ARR[I][J]; } cout<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define LAST_IDX(N) N-1
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();
#define MAX 500
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int main() {
    FASTIO

    int n;
    int i, j, k;
    int r[MAX + 1];
    int c[MAX + 1];
    int dp[MAX + 1][MAX + 1];

    memset(c, 0, sizeof(c));
    memset(r, 0, sizeof(r));
    memset(dp, 0, sizeof(dp));

    cin >> n;
    FOR_N_M(1, n, i) {
        cin >> r[i] >> c[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j + i <= n; j++) {

            int a = j;
            int b = j + i;

            dp[a][b] = INF;
            for (k = 0; k < b - a; k++) {
                int msum = r[a] * c[a + k] * c[b];
                dp[a][b] = min(dp[a][b], dp[a][a + k] + dp[a + k + 1][b] + msum);
            }
        }
    }

    cout << dp[1][n];
    PRT_ENTER
}