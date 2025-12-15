#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k; k--; 

    vi a(n); FOR(i,0,n) cin >> a[i];

    int last = a[n-1];
    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] != last) idx = i;
    }

    if (idx >= k) {
        cout << -1 << '\n';
    } else {
        cout << idx + 1 << '\n';
    }
}


int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
