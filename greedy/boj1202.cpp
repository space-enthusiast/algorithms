#define FOR(N, I) for(I=0;I<N;I++)
#define PRT_STR(ARR) printf(ARR);
#define PRT_INT(N) printf("%d", N);
#define PRT_INT_INT(N, M) printf("%d %d", N, M);
#define PRT_ARY_1D(ARR, N, I) for(I=0;I<N;I++) printf("%d ", ARR[I]);
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { printf("%d ", ARR[I][J]); } printf("\n"); }
#define PRT_ENTER printf("\n");
#define INP_INT_INT(N, M) scanf("%d %d", &N, &M);
#define LAST_IDX(N) (N-1)
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define MAX 300000

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    int i,j;
    int n,k;
    long long int res=0;
    pair<int, int> mv[MAX];
    int c[MAX];
    priority_queue<int> pq;

    INP_INT_INT(n,k)

    FOR(n,i) {
        scanf("%d %d", &mv[i].first, &mv[i].second);
    }

    FOR(k,i) {
        scanf("%d", &c[i]);
    }
    sort(mv, mv+n);
    sort(c, c+k);

    int idx=0;
    FOR(k,i){
        while(idx<n && mv[idx].first<=c[i]) {
            pq.push(mv[idx++].second);
        }

        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    printf("%lld", res);

    return 0;
}