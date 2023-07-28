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

    int arr[3];

    while (true) {
        cin >> arr[0] >> arr[1] >> arr[2];

        if (arr[0] == 0 OR arr[1] == 0 OR arr[2] == 0) {
            break;
        }
        sort(arr, arr + 3, greater<int>());

        if ((arr[1] + arr[2]) <= arr[0]) {
            cout << "Invalid\n";
        } else if (arr[2] == arr[1] AND arr[1] == arr[0]) {
            cout << "Equilateral\n";
        } else if (arr[2] == arr[1] OR arr[1] == arr[0] OR arr[1] == arr[2]) {
            cout << "Isosceles\n";
        } else {
            cout << "Scalene\n";
        }
    }

}