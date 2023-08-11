#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT_SET(SET) for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_SET_NAME(SET_NAME, SET) cout<<setw(6)<<SET_NAME<<": "; for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ARY_1D(ARR, N, I) for(I=0;I<N;I++){ cout<<ARR[I]<<' '; } cout<<"\n";
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { cout<<ARR[I][J]<<' '; } cout<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define LAST_IDX(N) (N-1)
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define NOT !
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();
#define MAX 1000000000
#define INF numeric_limits<long>::max()
#define NUM long long int

#include <bits/stdc++.h>

using namespace std;

NUM n, m;
NUM i, j, k;

NUM f(NUM val) {
    NUM size = 0, temp;
    FOR_N_M(1, n, i) {
        temp = val / i;
        if (temp > n) temp = n;
        size += temp;
    }
    return size;
}

int main() {
    FASTIO

    cin >> n >> k;

    NUM start = 1, end = n * n, mid;
    NUM ans = INF;

    while (start <= end) {

        mid = (start + end) / 2;

        NUM max_idx = f(mid);

        if (k <= max_idx) {
            ans = min(ans, mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << ans;
}