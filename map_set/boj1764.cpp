#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT(A) cout<<(A);
#define PRT_ARY_1D(ARR, N, I) for(I=0;I<N;I++){ cout<<ARR[I]<<' '; } cout<<"\n";
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { cout<<ARR[I][J]<<' '; } cout<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define LAST_IDX(N) N-1
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define NOT !
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();
#define MAX 100000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int main() {
    FASTIO

    int n, m, i;
    string temp;
    set < string > s;
    set < string > s2;

    cin >> n >> m;

    FOR_N(n, i) {
        cin >> temp;
        s.insert(temp);
    }
    FOR_N(m, i) {
        cin >> temp;
        if (s.find(temp) != s.end()) {
            s2.insert(temp);
        }
    }

    cout << s2.size() << '\n';
    for (auto iter: s2) {
        cout << iter << '\n';
    }
}