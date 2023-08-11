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
#define MAX 200000
#define INF numeric_limits<long>::max()
#define NUM long long int

#include <bits/stdc++.h>

using namespace std;

NUM n, m, c;
NUM i, j, k;

NUM arr[MAX + 1];

NUM possible(NUM min_size) {
    NUM idx = 0, cnt = 1;
    NUM curr = arr[idx] + min_size;

    while (idx <= LAST_IDX(n)) {
        if (arr[idx] >= curr) {
            curr = arr[idx] + min_size;
            cnt++;
            idx += 1;
        } else {
            idx++;
        }
    }

    return cnt;
}

int main() {
    FASTIO

    cin >> n >> c;

    FOR_N(n, i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    NUM start = 0;
    NUM end = INF;
    NUM mid, ans = 0;

    while (start <= end) {
        mid = (start + end) / 2;

        if (possible(mid) >= c) {
            ans = max(mid, ans);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << ans;
}