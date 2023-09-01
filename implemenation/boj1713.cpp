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

    NUM photo_num, temp;

    cin >> photo_num >> n;
    vector<pair<NUM, pair<NUM, NUM>>> arr;
    // (학생 번호 (힉생 추천수, 들어온 순서))

    FOR_N(n, i) {
        cin >> temp;

        NUM exist_human = -1;
        for (NUM idx = 0; idx < arr.size(); idx++) {
            if (arr[idx].first == temp) {
                exist_human = idx;
            }
        }


        if (exist_human != -1) { // 이미 존재하면 추천수 상승
            arr[exist_human].second.first += 1;
        } else if (arr.size() < photo_num) { // 안 존재하고 사진틀 남으면 삽입
            arr.push_back({temp, {1, i}});
        } else if (arr.size() >= photo_num) { // 안 존재하고 사진틀 차있으면 추천수와 온순으로 한명 추출

            NUM old_human_idx;
            NUM lowest_recommend = INF;
            NUM first_come_i = INF;
            for (NUM idx = 0; idx < arr.size(); idx++) {
                lowest_recommend = min(lowest_recommend, arr[idx].second.first);
            }

            for (NUM idx = 0; idx < arr.size(); idx++) {
                if (arr[idx].second.first == lowest_recommend) {
                    first_come_i = min(first_come_i, arr[idx].second.second);
                }
            }

            for (NUM idx = 0; idx < arr.size(); idx++) {
                if (arr[idx].second.first == lowest_recommend AND arr[idx].second.second == first_come_i) {
                    old_human_idx = idx;
                }
            }

            arr.erase(arr.begin() + old_human_idx);

            arr.push_back({temp, {1, i}});
        }
    }


    vector<NUM> ans;
    for (auto iter: arr) {
        ans.push_back(iter.first);
    }

    sort(ans.begin(), ans.end());
    for (auto a: ans) {
        cout << a << ' ';
    }
}