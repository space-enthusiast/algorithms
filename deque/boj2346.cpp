#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT_SET(SET) for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_SET_NAME(SET_NAME, SET) cout<<setw(6)<<SET_NAME<<": "; for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
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
#define NUM long long int
#define INI_ARR_NUM(ARR, N) NUM ARR[N]; memset(arr, 0, sizeof(ARR));
#define INI_ARR_VAL(ARR, N, INI_VAL) long long int (ARR)[(N)]; for (long long int i = 0; i < (N); i++) {(ARR)[i] = (INI_VAL); }
#define SIEVE_OF_ERATOSTHENE(ARR, N) long long int (ARR)[(N+1)]; (ARR)[1]=0; for (long long int SOE_IDX = 1;SOE_IDX<=N;SOE_IDX++) (ARR)[SOE_IDX] = 1; long long int SOR_SQRT_N = sqrt(N); for (long long int SOE_IDX = 2; SOE_IDX < SOR_SQRT_N; SOE_IDX++) { long long int SOE_TIMES = 2; if (ARR[SOE_IDX] == 0) continue; while (SOE_IDX * SOE_TIMES <= N) { (ARR)[SOE_IDX * SOE_TIMES] = 0; SOE_TIMES++; }}

#include <bits/stdc++.h>

using namespace std;

NUM n, m;
NUM i, j, k;

int main() {
    FASTIO

    cin >> n;
    NUM empty_value = n + 1;
    INI_ARR_NUM(arr, n)
    INI_ARR_VAL(visited, n, 0)
    FOR_N(n, i) {
        cin >> arr[i];
    }


    NUM cur_idx = 0;
    FOR_N(n, i) {

        cout << cur_idx + 1 << ' ';

        visited[cur_idx] = 1;

        NUM jump = arr[cur_idx];
        NUM right = jump >= 0;

        if (n - 1 == i) break;
        while (jump != 0) {
            if (right) {
                cur_idx++;
                if (cur_idx >= n) cur_idx = 0;
                if (NOT visited[cur_idx]) {
                    jump--;
                }
            } else {
                cur_idx--;
                if (cur_idx < 0) cur_idx = n - 1;
                if (NOT visited[cur_idx]) {
                    jump++;
                }
            }
        }
    }
}