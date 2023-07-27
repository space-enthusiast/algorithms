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
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();
#define MAX 500
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int main() {
    FASTIO

    int n, i;
    int maxx = -INF;
    int minx = INF;
    int maxy = -INF;
    int miny = INF;

    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    FOR_N(n, i) {
        int tmpa, tmpb;
        cin >> tmpa >> tmpb;

        maxy = max(maxy, tmpa);
        miny = min(miny, tmpa);
        maxx = max(maxx, tmpb);
        minx = min(minx, tmpb);
    }

    cout << abs(maxy - miny) * abs(maxx - minx);
}