
/**
*    author:  DwiD4r :)
**/
#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define pii pair<int, int>
#define ll long long
#define f first
#define s second
#define pb push_back
#define mb make_pair
#define int long long
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
#define sp " "
#define endl "\n"
#define yes "YES\n"
#define oo 0x3f3f3f3f3f3f3f3f
#define no "NO\n"
//dp[sum]=distinct number of way to get x
long long dp[10000005];
vector<long long> v;
int n,m;
const long long INF = LLONG_MAX / 4;
long long Mod = 1e9+7;
 
long long go(long long sum) {
    if (sum == 0) return 0;
    if (sum < 0) return INF;
 
    long long &ret = dp[sum];
    if (ret != -1) return ret;
 
    long long best = INF;
 
    for (int i = 0; i < n; ++i) {
        long long sub = go(sum - v[i]);
        if (sub != INF) {
            best = min(best, sub + 1);
        }
    }
 
    if (best >= INF) return ret = INF;
    return ret = (best % Mod);
}
 
 
void solve() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
 
    memset(dp, -1, sizeof(dp));
 
  if (go(m)==INF)cout<<-1<<endl;
    else cout<<go(m)<<endl;
}
 
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

