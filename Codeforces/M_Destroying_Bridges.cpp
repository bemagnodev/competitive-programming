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
const int INF = 1e9+7;
const int MAXN = 3e5+5;
vi dp(MAXN, INF);


vi cannon; 


void solve() {
    // freopen("knapsack.in", "r", stdin);   
    // freopen("knapsack.out", "w", stdout); 
    int s, n; cin >> s >> n;
    vi pesos(n);

    FOR(i,0,n) cin >> pesos[i];

    vi dp(s+1, 0);
    
    dp[0] = 1;
    int mx = 0;
    for(int p :pesos){
        ROF(i,p,s+1) {
            if(dp[i-p]){
                dp[i] = 1;
                mx = max(mx, i );
            }
        }
    }
    cout << mx << endl;

   // cout <<ans << endl;
    

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
