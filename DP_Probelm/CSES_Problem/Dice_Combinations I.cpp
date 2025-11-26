
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
int Mod = 1e9 + 7;
vector<int> v;
int n, m;
const int N = 1e6 + 5;
int dp[N];
bool arr[N];
int go(int sum) {
    if (sum == 0)return 1;
    if (sum < 0)return 0;
    int &ret = dp[sum];
    if (~ret) return ret;
    int ways = 0;
    for (int i = 0; i < n; ++i) {
        ways += go(sum - v[i]);
    }
    return ret = ways % Mod;
}
 
 
void solve() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
 
    cout << go(m) << endl;
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

