
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
// dp[i][j]=sum of way to reach (n,n);
int Mod = 1e9 + 7;
vector<vector<char> > v;
int n;
const int N = 1e6 + 5;
int dp[1005][1005];
int go(int i,int j) {
    if (i == n - 1 and j == n - 1) {
        if (v[i][j]!='*')
        return 1;
        return 0;
    }
    if (i==n and j==n)return 0;
 
    int &ret = dp[i][j];
    if (~ret)return ret;
 
 
    if (i > n - 1 || j > n - 1)return 0;
    if (v[i][j] == '*')return 0;
 
        return ret = ((go(i + 1, j) % Mod) + (go(i, j + 1) % Mod)) % Mod;
}
 
void solve() {
    cin >> n;
    v.resize(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
 
    cout << go(0, 0) << endl;
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

