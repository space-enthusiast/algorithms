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
#define INI_ARR_NUM(ARR, N) NUM ARR[N]; memset(arr, 0, sizeof(ARR));

#include <bits/stdc++.h>

using namespace std;

NUM n, m;
NUM i, j, k;

int main() {
    FASTIO

    deque<NUM> dq;

    cin >> n;
    FOR_N(n, i) {
        NUM temp, tempb;
        cin >> temp;

        if (temp == 1) {
            cin >> tempb;
            dq.push_front(tempb);
        } else if (temp == 2) {
            cin >> tempb;
            dq.push_back(tempb);
        } else if (temp == 3) {
            if (NOT dq.empty()) {
                PRT(dq.front())
                dq.pop_front();
            } else {
                PRT(-1)
            }
        } else if (temp == 4) {
            if (NOT dq.empty()) {
                PRT(dq.back())
                dq.pop_back();
            } else {
                PRT(-1)
            }
        } else if (temp == 5) {
            PRT(dq.size())
        } else if (temp == 6) {
            PRT(dq.empty())
        } else if (temp == 7) {
            if (NOT dq.empty()) {
                PRT(dq.front())
            } else {
                PRT(-1)
            }
        } else if (temp == 8) {
            if (NOT dq.empty()) {
                PRT(dq.back())
            } else {
                PRT(-1)
            }
        }
    }
}