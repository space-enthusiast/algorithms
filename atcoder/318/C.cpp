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
#define MAX 200000
#define INF numeric_limits<long>::max()
#define NUM long long int
#define INI_ARR_NUM(ARR, N) NUM ARR[N]; memset(ARR, 0, sizeof(ARR));
#define INI_ARR_VAL(ARR, N, INI_VAL) long long int (ARR)[(N)]; for (long long int i = 0; i < (N); i++) {(ARR)[i] = (INI_VAL); }
#define SIEVE_OF_ERATOSTHENE(ARR, N) long long int (ARR)[(N+1)]; (ARR)[1]=0; for (long long int SOE_IDX = 1;SOE_IDX<=N;SOE_IDX++) (ARR)[SOE_IDX] = 1; long long int SOR_SQRT_N = sqrt(N); for (long long int SOE_IDX = 2; SOE_IDX < SOR_SQRT_N; SOE_IDX++) { long long int SOE_TIMES = 2; if (ARR[SOE_IDX] == 0) continue; while (SOE_IDX * SOE_TIMES <= N) { (ARR)[SOE_IDX * SOE_TIMES] = 0; SOE_TIMES++; }}
#define EXIST(EXIST_ITER, N) EXIST_ITER.find(N) != EXIST_ITER.end()

#include <bits/stdc++.h>

using namespace std;

NUM n, m, d, p, f;
NUM i, j, k;
NUM arr[MAX];
double one_day_ticket_price;
NUM price;
vector<NUM> smaller;
vector<NUM> bigger;
vector<NUM> left_arr;

int main() {
    FASTIO


    cin >> n >> d >> p;

    one_day_ticket_price = (double) p / d;

    FOR_N(n, i) {
        cin >> arr[i];
        if (one_day_ticket_price < arr[i]) {
            bigger.push_back(arr[i]);
        } else {
            smaller.push_back(arr[i]);
        }
    }

    sort(arr, arr + n);
    sort(smaller.begin(), smaller.end(), greater<>());
    sort(bigger.begin(), bigger.end());

    if (bigger.size() / d > 0) {
        price += (bigger.size() / d) * p;
    }

//    PRT_ARY_1D(arr, n)
//    PRT_NAME("bigger.size() % d", bigger.size() % d)
    for (int iter = 0; iter < bigger.size() % d; iter++) {
        left_arr.push_back(bigger[iter]);
    }

//    PRT_NAME("one_day_ticket_price", one_day_ticket_price)
//    PRT_ARY_1D(arr, n)
    NUM use_left_arr_price = price;
    NUM not_use_left_arr_price = price;

    use_left_arr_price += p;
    NUM ticket = d;
    ticket -= left_arr.size();
    for (auto sm: smaller) {
        if (ticket > 0) {
            ticket--;
        } else {
            use_left_arr_price += sm;
        }
    }

    for (auto lef: left_arr) {
        not_use_left_arr_price += lef;
    }
    for (auto sm: smaller) {
        not_use_left_arr_price += sm;
    }

    if (not_use_left_arr_price <= use_left_arr_price) {
        PRT(not_use_left_arr_price)
    } else {
        PRT(use_left_arr_price)
    }
}