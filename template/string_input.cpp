#define FOR(N, I) for(I=0;I<N;I++)
#define PRT(A) cout<<(A);
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { cout<<ARR[I][J]; } cout<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define LAST_IDX(N) N-1
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#include <bits/stdc++.h>
using namespace std;

int main() {
    FASTIO

    string arr;
    getline (cin, arr);
    cout<<arr<<endl;
}