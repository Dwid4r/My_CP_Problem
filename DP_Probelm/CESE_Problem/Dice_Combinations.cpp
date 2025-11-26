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
//dp[i][sum]=number of way to get x
int Mod = 1e9 + 7;
vector<int> v = {1, 2, 3, 4, 5, 6};
int n;
const int N = 1e6 + 5;
int dp[N];
int go(int sum) {
    if (sum == 0)return 1;
    if (sum < 0)return 0;
    int &ret = dp[sum];
    if (~ret) return ret;
    int ways = 0;
    ways += go(sum - 1);
    ways += go(sum - 2);
    ways += go(sum - 3);
    ways += go(sum - 4);
    ways += go(sum - 5);
    ways += go(sum - 6);
 
    return ret = ways % Mod;
}
 
void built(int i,int j) {
}
 
 
void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
 
    cout << go(n) << endl;
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

