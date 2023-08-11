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
#define MAX 1000000
#define INF numeric_limits<long>::max()
#define NUM long long int

#include <bits/stdc++.h>

using namespace std;

NUM n, m;
NUM i, j, k;

int main() {
    FASTIO

    stack<NUM> s;

    cin >> n;

    NUM tempa, tempb;

    FOR_N(n, i) {
        cin >> tempa;

        if (tempa == 1) {
            cin >> tempb;
            s.push(tempb);
        }

        if (tempa == 2) {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        }

        if (tempa == 3) {
            cout << s.size() << '\n';
        }

        if (tempa == 4) {
            if (s.size() <= 0) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }

        if (tempa == 5) {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.top() << "\n";
            }
        }
    }
}