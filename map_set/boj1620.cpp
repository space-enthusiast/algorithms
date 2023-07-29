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

    map<string, int> dicta;
    map<int, string> dictb;

    int n, i, m;
    string temp;
    string ans[100000];

    cin >> n >> m;
    int cnt = 0;
    FOR_N(n, i) {
        cin >> temp;
        dicta.insert({temp, ++cnt});
        dictb.insert({cnt, temp});
    }

    FOR_N(m, i) {
        cin >> ans[i];
    }
    
    FOR_N(m, i) {
        if (dicta.find(ans[i]) != dicta.end()) {
            cout << dicta.find(ans[i])->second << '\n';
        } else {
            cout << dictb.find(stoi(ans[i]))->second << '\n';
        }
    }
}