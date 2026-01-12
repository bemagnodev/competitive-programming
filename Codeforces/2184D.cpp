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

ll combinacao(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    ll r = 1;
    FOR(i,1,k+1) {
        r = r * (n - i + 1) / i;
    }
    return r;
}
void solve() {
    int n, k; cin >> n >> k;
    int d = log2(n);
    ll ans = 0;
    // i -> MSB
    FOR(i,0,d){
        if( 2*i +1< k) continue;
        ll restante_min =max( 0, (k - (i+1) +1));
        FOR(j, restante_min, i+1){
            ans += combinacao(i,j);
        }
    }
    // n
    if ((d + 1) > k) {
        ans++;
    }

    cout << ans << endl;

}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
