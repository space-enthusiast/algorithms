#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define INF 1000000010
#define FOR(x, n) for(int x=0; x<n; x++)
#define ini(x, n) memset(x, n, sizeof(x));
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define MAX 100000+1
#define MOD 1000000000
using namespace std;


int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1};


struct Time{
    int begin;
    int end;
};

bool cmp(Time f, Time s){
    if(f.end == s.end){
        return f.begin<s.begin;
    }else{
        return f.end<s.end;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<Time> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].begin>>v[i].end;
    }

    sort(all(v), cmp);

    int cnt=0;
    int end=0;

    for(int i=0;i<n;i++){
        if(end<=v[i].begin){
            end=v[i].end;
            cnt++;
        }
    }

    cout<<cnt;

    return 0;
}