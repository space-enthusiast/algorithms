#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT_SET(SET) for (auto i: SET) { cout << i << ' '; } cout<<"\n";
#define PRT_SET_NAME(SET_NAME, SET) cout<<setw(6)<<SET_NAME<<": "; for (auto i: SET) { cout << i << ' '; } cout<<"\n";
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
#define MAX 100000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int main() {
    FASTIO

    set<int> setA;
    set<int> setB;
    set<int> result;

    result.clear();
    setA.clear();
    setB.clear();
    setA.insert({1, 2, 3});
    setB.insert({4, 5});
    PRT("A ∪ B: ")
    PRT_SET_NAME("setA", setA)
    PRT_SET_NAME("setB", setB)
    set_union(setA.begin(), setA.end(), setB.begin(), setB.end(),
              inserter(result, result.begin()));
    PRT_SET_NAME("result", result)

    PRT_DEBUG_LINE

    result.clear();
    setA.clear();
    setB.clear();
    setA.insert({1, 2, 3, 4, 5});
    setB.insert({1, 2, 3});
    PRT("A ∩ B: ")
    PRT_SET_NAME("setA", setA)
    PRT_SET_NAME("setB", setB)
    set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                     inserter(result, result.begin()));
    PRT_SET_NAME("result", result)

    PRT_DEBUG_LINE

    result.clear();
    setA.clear();
    setB.clear();
    setA.insert({1, 2, 3, 4, 5});
    setB.insert({1, 2, 3});
    PRT("A - B: ")
    PRT_SET_NAME("setA", setA)
    PRT_SET_NAME("setB", setB)
    set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                   inserter(result, result.begin()));
    PRT_SET_NAME("result", result)

    return 0;
}