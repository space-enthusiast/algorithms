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
#define MAX 9000000000
#define INF numeric_limits<long>::max()
#define NUM long long int

#include <bits/stdc++.h>

using namespace std;

bool is_p(NUM p) {
    int k;
    if (p < 2) {
        return false;
    } else {
        FOR_N_M(2, (NUM) sqrt(p), k) {
            if (p % k == 0) return false;
        }
        return true;
    }
}

int main() {
    FASTIO

    NUM n, m, i, j;

    cin >> n;

    FOR_N(n, i) {
        cin >> m;
        if (m == 0) {
            cout << "2\n";
        } else {
            FOR_N_M(m, MAX, j) {
                if (is_p(j)) {
                    cout << j << '\n';
                    break;
                } else {
                    continue;
                }
            }
        }
    }
}