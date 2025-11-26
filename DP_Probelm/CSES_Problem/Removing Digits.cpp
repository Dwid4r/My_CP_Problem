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
int mod = 100000000;
// int n;
const int INF = 1e9;
vector<int> memo;
int go(int sum) {
    if (sum == 0) return 0;
    if (sum > (int)memo.size() - 1) return INF; // FIX
 
    if (memo[sum] != -1) return memo[sum];
 
    string s = to_string(sum);
    int best = INF;
    for (char c : s) {
        int d = c - '0';
        if (d == 0) continue;
        best = min(best, 1 + go(sum - d));
    }
 
    return memo[sum] = best;
}
void solve() {
    int n;
    if (!(cin >> n)) return ;
    memo.assign(n + 1, -1);
    cout << go(n) << "\n";
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

