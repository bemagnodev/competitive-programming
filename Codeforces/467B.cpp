#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n,m,k; cin >> n>> m >> k;
    vi players(m+1);
    FOR( i, 0, m+1){
        cin >> players[i];
    }

    int fed = players[m];
    ll ans = 0;

    FOR(i, 0 , m){
        int nbits = __builtin_popcount(fed ^ players[i]);
        if(nbits <=k) ans++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    // cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}
