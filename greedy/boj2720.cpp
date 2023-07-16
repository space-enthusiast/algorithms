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

void solution(int n) {

    int change = n;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    PRT(change/quarter)
    change -= (change/quarter*quarter);
    PRT(" ")
    PRT(change/dime)
    change -= (change/dime*dime);
    PRT(" ")
    PRT(change/nickel)
    change -= (change/nickel*nickel);
    PRT(" ")
    PRT(change/penny)
    change -= (change/penny*penny);
    PRT(" ")
    PRT_ENTER
}

int main() {
    FASTIO
    int n,i;
    cin>>n;

    FOR(n,i) {
        int temp;
        cin>>temp;
        solution(temp);
    }
}