#define FOR(N, I) for(I=0;I<N;I++)
#define PRT(A) count<<(A);
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { cout<<ARR[I][J]; } count<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define LAST_IDX(N) N-1
#define FIRST_IDX 0
#define AND &&
#define OR ||

#include <bits/stdc++.h>
using namespace std;

void setup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    setup();

    priority_queue<int> pq;

    int n,i;
    cin>>n;

    FOR(n,i){
        int temp;
        cin>>temp;

        if (temp == 0 AND !pq.empty()) {
            cout<<pq.top();
            PRT_ENTER
            pq.pop();
        } else if (temp == 0) {
            cout<<0;
            PRT_ENTER
        } else if (temp != 0) {
            pq.push(temp);
        }
    }
}