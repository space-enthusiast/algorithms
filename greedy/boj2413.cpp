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
#define MAX 50000+1

#include <bits/stdc++.h>
using namespace std;

int main() {
    FASTIO

    int n,i;
    int temp;
    int reserve[MAX]={0,};
    int used[MAX]={0,};

    cin>>n;

    FOR_N(n,i){
        cin>>temp;
        if(reserve[temp]!=0){
            cout<<reserve[temp]<<' ';
            used[reserve[temp]]=1;
        }else if(temp>=2 AND used[temp-1]==0){
            cout<<temp-1<<' ';
            reserve[temp-1]=temp;
            used[temp]=1;
            used[temp-1]=1;
        }else{
            cout<<temp<<' ';
            used[temp]=1;
        }
    }
}