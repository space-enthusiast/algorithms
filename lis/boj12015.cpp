#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT_SET(SET) for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_SET_NAME(SET_NAME, SET) cout<<setw(6)<<SET_NAME<<": "; for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_VEC_NAME(VEC_NAME, VEC) cout<<setw(6)<<VEC_NAME<<": "; for (auto VEC_ITER: VEC) { cout << VEC_ITER << ' '; } cout<<"\n";
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

    INI_ARR_NUM(arr, MAX + 1)

    cin >> n;
    FOR_N_M(1, n, i) {
        cin >> arr[i];
    }

    vector<NUM> vec;
    vec.push_back(arr[1]);
    FOR_N_M(2, n, i) {
        if (vec.back() < arr[i]) {
            vec.push_back(arr[i]);
        } else {
            int low = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            vec[low] = arr[i];
        }
    }

    PRT(vec.size())
}
/*
8
5 2 8 6 3 6 9 5
4

6
10 20 10 30 20 50
4

5
1 2 3 4 5
5
 */