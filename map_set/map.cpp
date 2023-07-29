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

    map<string, int> m;
//    map<int, int, greater<>> map_desc_key;

    m.insert({"hello", 1});
    m.insert({"world", 2});

    cout << "find map data with stl find: \n";
    int a = m.find("hello")->second;
    if (m.find("hello") != m.end()) {
        cout << "found key hello value : " << a << "\n";
    } else {
        cout << "not found\n";
    }
    PRT_ENTER

    cout << "traverse map with iterator: \n";
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " : " << iter->second << '\n';
    }
    PRT_ENTER

    cout << "traverse map with iterator: \n";
    for (auto iter: m) {
        cout << iter.first << " " << iter.second << endl;
    }
    PRT_ENTER

    cout << "erase map by index or key: \n";
    m.erase(m.begin());
    m.erase(m.begin(), m.end());
    m.erase("hello");
    for (auto iter: m) {
        cout << iter.first << " " << iter.second << endl;
    }
    PRT_ENTER


    cout << "erase all map: \n";
    m.insert({"hello", 1});
    for (auto iter: m) {
        cout << iter.first << " " << iter.second << endl;
    }
    m.clear();
    for (auto iter: m) {
        cout << iter.first << " " << iter.second << endl;
    }
    PRT_ENTER
}