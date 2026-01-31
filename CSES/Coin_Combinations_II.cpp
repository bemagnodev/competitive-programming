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
    int n, x; cin >> n >> x;
    vi c(n); FOR(i,0,n) cin >> c[i];
    vl dp(x+1,0);

    dp[0] =1;
    for(int coin : c){
        FOR(i,0, x+1){
            if(i-coin >= 0){
                dp[i] = (dp[i] + dp[i - coin]) %MOD;
            }
        }
    }
    cout << dp[x] << "\n";
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
