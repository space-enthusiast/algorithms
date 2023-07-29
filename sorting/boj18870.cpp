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
#define NOT !
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();
#define MAX 1000000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int main() {
    FASTIO

    int n, i;
    int arr[MAX];
    int sorted[MAX];
    cin >> n;

    FOR_N(n, i) {
        cin >> arr[i];
        sorted[i] = arr[i];
    }

    sort(sorted, sorted + n);

    int si = 0;
    int sj = 1;
    while (true) {
        if (sj >= n) {
            break;
        }
        if (sorted[si] == sorted[sj]) {
            sj++;
        } else {
            sorted[++si] = sorted[sj++];
        }
    }

    FOR_N(n, i) {
        int x = arr[i];
        int bsi = 0, bsj = si;
        int idx;
        while (true) {

            idx = (bsj - bsi + 1) / 2 + bsi;

            if (NOT(bsi <= bsj)) {
                cout << 0 << '\n';
                break;
            }

            if (sorted[idx] == x) {
                cout << idx << ' ';
                break;
            } else if (sorted[idx] < x) {
                bsi = idx + 1;
            } else if (x < sorted[idx]) {
                bsj = idx - 1;
            }
        }
    }
}