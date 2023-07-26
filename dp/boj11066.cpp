#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT(A) cout<<(A);
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { cout<<ARR[I][J]; } cout<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define LAST_IDX(N) N-1
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();
#define MAX 500
#define INF 2147483647

#include <bits/stdc++.h>
using namespace std;

int main() {
    FASTIO

    int n,ni,k,i,j;
    int arr[MAX+1];
    int sum[MAX+1];
    int dp[MAX+1][MAX+1];

    cin>>n;

    FOR_N(n,ni){

        memset(arr, 0, sizeof(arr));
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));

        cin>>k;
        FOR_N_M(1,k,i) {
            cin>>arr[i];
            sum[i]=sum[i-1]+arr[i];
        }

        for (i=1;i<=k;i++){
            for (j=1;j+i<=k;j++){

                int a=j;
                int b=j+i;
                int psum=sum[j+i]-sum[j-1];

                dp[a][b]=INF;
                for (int it=0;it<b-a;it++){
                    dp[a][b]=min(dp[a][b], dp[a][a+it] + dp[a+it+1][b] +psum);
                }
            }
        }
        cout<<dp[1][k];
        PRT_ENTER
    }
}