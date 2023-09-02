#define FOR_N(N, I) for(I=0;I<N;I++)
#define FOR_N_M(N, M, I) for(I=N;I<=M;I++)
#define PRT_SET(SET) for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT_SET_NAME(SET_NAME, SET) cout<<SET_NAME<<": "; for (auto SET_ITER: SET) { cout << SET_ITER << ' '; } cout<<"\n";
#define PRT(A) cout<<(A)<<'\n';
#define PRT_NAME(A_NAME, A) cout<<(A_NAME)<<": "<<(A)<<'\n';
#define PRT_ARY_1D(ARR, N) for(long long int PRT_ARY_1D_IDX=0;PRT_ARY_1D_IDX<N;PRT_ARY_1D_IDX++){ cout<<ARR[PRT_ARY_1D_IDX]<<' '; } cout<<"\n";
#define PRT_ARY_2D(ARR, N, M) for(long long int PRT_ARY_2D_I=0;PRT_ARY_2D_I<N;PRT_ARY_2D_I++){ for(long long int PRT_ARY_2D_J=0;PRT_ARY_2D_J<M;PRT_ARY_2D_J++) { cout<<ARR[PRT_ARY_2D_I][PRT_ARY_2D_J]<<' '; } cout<<"\n"; }
#define PRT_ENTER cout<<"\n";
#define PRT_DEBUG_LINE cout<<'\n'<<"================"<<'\n';
#define LAST_IDX(N) (N-1)
#define FIRST_IDX 0
#define AND &&
#define OR ||
#define NOT !
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define top_pop(pq) (pq).top();(pq).pop();
#define MAX 1000000
#define INF numeric_limits<long>::max()
#define NUM long long int
#define INI_ARR_NUM(ARR, N) NUM ARR[N]; memset(ARR, 0, sizeof(ARR));
#define INI_ARR_VAL(ARR, N, INI_VAL) long long int (ARR)[(N)]; for (long long int i = 0; i < (N); i++) {(ARR)[i] = (INI_VAL); }
#define SIEVE_OF_ERATOSTHENE(ARR, N) long long int (ARR)[(N+1)]; (ARR)[1]=0; for (long long int SOE_IDX = 1;SOE_IDX<=N;SOE_IDX++) (ARR)[SOE_IDX] = 1; long long int SOR_SQRT_N = sqrt(N); for (long long int SOE_IDX = 2; SOE_IDX < SOR_SQRT_N; SOE_IDX++) { long long int SOE_TIMES = 2; if (ARR[SOE_IDX] == 0) continue; while (SOE_IDX * SOE_TIMES <= N) { (ARR)[SOE_IDX * SOE_TIMES] = 0; SOE_TIMES++; }}
#define EXIST(EXIST_ITER, N) EXIST_ITER.find(N) != EXIST_ITER.end()

#include <bits/stdc++.h>

using namespace std;

NUM n, m;
NUM i, j, k;

int main() {
    FASTIO

    NUM a[4 + 1][4 + 1];
    NUM t, iter;

    cin >> t;
    FOR_N(t, iter) {
        FOR_N_M(1, 3, i) {
            FOR_N_M(1, 4, j) {
                cin >> a[i][j];
            }
        }

        // detA, detA1, detA2, detA3 구하기
        NUM detA = a[1][1] * (a[2][2] * a[3][3] - a[2][3] * a[3][2])
                   - a[1][2] * (a[2][1] * a[3][3] - a[2][3] * a[3][1])
                   + a[1][3] * (a[2][1] * a[3][2] - a[2][2] * a[3][1]);

        NUM detA1 = a[1][4] * (a[2][2] * a[3][3] - a[2][3] * a[3][2])
                    - a[1][2] * (a[2][4] * a[3][3] - a[2][3] * a[3][4])
                    + a[1][3] * (a[2][4] * a[3][2] - a[2][2] * a[3][4]);

        NUM detA2 = a[1][1] * (a[2][4] * a[3][3] - a[2][3] * a[3][4])
                    - a[1][4] * (a[2][1] * a[3][3] - a[2][3] * a[3][1])
                    + a[1][3] * (a[2][1] * a[3][4] - a[2][4] * a[3][1]);

        NUM detA3 = a[1][1] * (a[2][2] * a[3][4] - a[2][4] * a[3][2])
                    - a[1][2] * (a[2][1] * a[3][4] - a[2][4] * a[3][1])
                    + a[1][4] * (a[2][1] * a[3][2] - a[2][2] * a[3][1]);

        cout << detA1 << ' ' << detA2 << ' ' << detA3 << ' ' << detA << '\n';
        if (detA == 0) {
            cout << "No unique solution";
        } else {
            cout << "Unique solution: ";
            double x1 = (double) detA1 / (double) detA;
            double x2 = (double) detA2 / (double) detA;
            double x3 = (double) detA3 / (double) detA;

            // -0.000 -> 0.000 으로 바꾸기
            if (x1 == 0) {
                x1 = 0;
            }
            if (x2 == 0) {
                x2 = 0;
            }
            if (x3 == 0) {
                x3 = 0;
            }

            // 소수점 3째 자리까지 출력
            cout << std::fixed << std::setprecision(3) << x1 << ' ';
            cout << std::fixed << std::setprecision(3) << x2 << ' ';
            cout << std::fixed << std::setprecision(3) << x3;

        }

        // 마지막 문장은 enter 출력 제외
        if (iter != t - 1) {
            PRT("")
            PRT("")
        }
    }

}

/*
1
1 2 3 1
1 1 1 2
2 2 2 3

1 -2 1 0
No unique solution

1
4 0 0 1
0 2 0 2
0 0 1 4

2 8 32 8
Unique solution: 0.250 1.000 4.000

*/