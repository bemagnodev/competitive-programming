#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define deb(k) cerr << #k << ": " << k << "\n";
#define pb push_back
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;  
const int INF = 1e9;
const ll INFLL = 4e18;

void solve() {
    vi a(3); FOR(i,0,3) cin >> a[i];
    sort(all(a));

    if(a[0] +a[1] == a[2]) cout <<"YES\n";
    else cout <<"NO\n";

}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
