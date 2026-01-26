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
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  

const int INF = 1e9+5;  


void solve() {
    int n; cin >> n;
    vi a(n), freq(n+1,0);
    bool um = false;
    FOR(i,0,n){
        cin >> a[i];
        if(a[i] == 1) um = true;

        freq[a[i]]++;
    } 
    vi s;
    FOR(i,2,n+1){
        if(freq[i] > 0) s.pb(i);
    }
    
    vi dp(n+1, INF);
    //base
    for(int x : s){
        dp[x] = 1;
    }
    if(um) dp[1] = 1;

    FOR(i,1,n+1){
        if(dp[i]== INF) continue;
        for(int x : s){
            ll prox = (ll)i* x;
            if(prox > n) break;
            dp[prox] = min(dp[prox], dp[i]+1);
        }
    }

    FOR(i,1,n+1){
        if(dp[i] == INF) cout << -1 << " ";
        else cout << dp[i] << " ";
    }
    cout << "\n";

}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
