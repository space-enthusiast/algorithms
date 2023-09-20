#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 100000

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, k;

deque<ll> dq;
int check[MAX + 1];

ll bfs(ll r) {
    check[r] = 1;
    dq.push_back(r);
    while (!dq.empty()) {
        ll u = dq.front();
        dq.pop_front();

        ll a, b, c;
        a = u - 1;
        b = u + 1;
        c = u * 2;

        if (0 <= a && a <= MAX) {
            if (check[a] == 0) {
                check[a] = check[u] + 1;
                dq.push_back(a);
            }
        }
        if (0 <= b && b <= MAX) {
            if (check[b] == 0) {
                check[b] = check[u] + 1;
                dq.push_back(b);
            }
        }
        if (0 <= c && c <= MAX) {
            if (check[c] == 0) {
                check[c] = check[u] + 1;
                dq.push_back(c);
            }
        }
    }

    return check[k] - 1;
}

int main() {
    FASTIO

    cin >> n >> k;

    if (k < n) {
        cout << n - k;
    } else {
        cout << bfs(n);
    }
}