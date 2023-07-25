#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT(A) cout<<(A);
#define PRT_ARY_2D(ARR, N, M, I, J) for(I=0;I<N;I++){ for(J=0;J<M;J++) { cout<<ARR[I][J]; } cout<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define LAST_IDX(N) N-1
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();

#include <bits/stdc++.h>
using namespace std;

int main() {
    FASTIO

    long long n,k,i,j;
    long long temp,sum;
    priority_queue<long long, vector<long long>, greater<>> pq;

    cin>>n;
    FOR_N(n,i){

        sum=0;

        cin>>k;

        FOR_N(k,j){
            cin>>temp;
            pq.push(temp);
        }

        while(pq.size()>=2){
            long long a = top_pop(pq)
            long long b = top_pop(pq)
            sum += (a+b);
            pq.push(a+b);

            if(pq.size()<=1){
                pq.pop();
                break;
            }
        }

        cout<<sum;
        PRT_ENTER
    }
}