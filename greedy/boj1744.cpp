#define FOR(N, I) for(I=0;I<N;I++)
#define PRT(A) cout<<(A);
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { cout<<ARR[I][J]; } cout<<"\n"; }
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

    priority_queue<int> pqb;
    priority_queue<int, vector<int>, greater<>> pqs;
    queue<int> pq0;
    queue<int> pq1;

    int n,i,res=0;
    cin>>n;

    FOR(n,i) {
        int temp;
        cin>>temp;
        if (temp == 1) {
            pq1.push(1);
        } else if (temp > 0) {
            pqb.push(temp);
        } else if (temp < 0) {
            pqs.push(temp);
        } else {
            pq0.push(0);
        }
    }

    while(pqb.size()>=2) {
        int a = pqb.top();
        pqb.pop();
        int b = pqb.top();
        pqb.pop();
        res += (a*b);
    }
    if (!pqb.empty()) {
        res += pqb.top();
        pqb.pop();
    }
    res += pq1.size();

    while(pqs.size()>=2) {
        int a = pqs.top();
        pqs.pop();
        int b = pqs.top();
        pqs.pop();
        res += (a*b);
    }
    if (!pqs.empty() AND pq0.empty()) {
        res += pqs.top();
        pqs.pop();
    }

    PRT(res)
}