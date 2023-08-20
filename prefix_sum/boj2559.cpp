#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT_SET(SET) for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_SET_NAME(SET_NAME, SET) cout<<setw(6)<<SET_NAME<<": "; for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ARY_1D(ARR, N) for(long long int PRT_ARY_1D_IDX=0;PRT_ARY_1D_IDX<N;PRT_ARY_1D_IDX++){ cout<<ARR[PRT_ARY_1D_IDX]<<' '; } cout<<"\n";
#define PRT_ARY_2D(ARR, N, M) for(long long int PRT_ARY_2D_I=0;PRT_ARY_2D_I<N;PRT_ARY_2D++){ for(long long int PRT_ARY_2D_J=0;PRT_ARY_2D_J<M;PRT_ARY_2D_J++) { cout<<ARR[PRT_ARY_2D_I][PRT_ARY_2D_J]<<' '; } cout<<"\n"; }
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
#define NUM long long int
#define INI_ARR_NUM(ARR, N) NUM ARR[N]; memset(arr, 0, sizeof(ARR));

#include <bits/stdc++.h>

using namespace std;

NUM n, m;
NUM i, j, k;

int main() {
    FASTIO

    NUM ans = -INF;
    cin >> n >> k;

    INI_ARR_NUM(arr, n)
    FOR_N(n, i) {
        cin >> arr[i];
        if (i != 0) {
            arr[i] += arr[i - 1];
        }
    }

    k -= 1;
    for (i = 0; i + k < n; i++) {
        if (i - 1 < 0) {
            ans = max(ans, arr[i + k]);
        } else {
            ans = max(ans, arr[i + k] - arr[i - 1]);
        }
    }

    PRT(ans)
}