#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT_SET(SET) for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_SET_NAME(SET_NAME, SET) cout<<setw(6)<<SET_NAME<<": "; for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_VEC(VEC) for (auto VEC_ITER: VEC) { cout << VEC_ITER << ' '; } cout<<"\n";
#define PRT_VEC_NAME(VEC_NAME, VEC) cout<<VEC_NAME<<": "; for (auto VEC_ITER: VEC) { cout << VEC_ITER << ' '; } cout<<"\n";
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
    FOR_N(n, i) {
        cin >> arr[i];
    }

    vector<NUM> vec;
    vector<NUM> vec2;

    vec2.push_back(vec.size());
    vec.push_back(arr[0]);

    FOR_N_M(1, n - 1, i) {
        if (vec.back() < arr[i]) {
            vec2.push_back(vec.size());
            vec.push_back(arr[i]);
        } else {
            NUM low = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            vec[low] = arr[i];
            vec2.push_back(low);
        }
    }

    stack<NUM> s;
    NUM pos = vec.size() - 1;
    for (NUM it = n - 1; it >= 0; it--) {
        if (vec2[it] == pos) {
            s.push(arr[it]);
            pos--;
        }
    }

    PRT(s.size())
    while (NOT s.empty()) {
        cout << top_pop(s)
        cout << ' ';
    }
}
/*
반례
9
3 4 7 7 4 2 6 9 9

출력
4
2 4 6 9

정답 예시
4
3 4 6 9

4
2 4 6 1
3
2 4 6

10
10 11 12 1 2 20 23 3 4 5

5
1 2 3 4 5

3
1 1 2

*/