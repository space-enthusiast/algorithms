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
#define MAX 10000
#define INF 2147483647
#define INF_LONG numeric_limits<long>::max()
#define STOP_DEBUG return 1;

#include <bits/stdc++.h>

using namespace std;

int main() {
    FASTIO

    int i, n, k, j;
    int arr[MAX + 1];

    cin >> k >> n;
    FOR_N(k, i) {
        cin >> arr[i];
    }

    sort(arr, arr + k, greater<>());

    long long int lan_max = arr[0];
    long long int lan_min = 1;
    long long int lan_size;
    long long res = 0;
    while (lan_min <= lan_max) {

        lan_size = (lan_max + lan_min) / 2;

        long long int lan_cnt = 0;
        FOR_N(k, i) {
            lan_cnt += arr[i] / lan_size;
        }

        if (lan_cnt >= n) {
            lan_min = lan_size + 1;
            res = max(res, lan_size);
        } else {
            lan_max = lan_size - 1;
        }
    }

    cout << res;
}

/*
4 11
802
743
457
539

2 1
1
101
*/