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
    freopen("lepus.in", "r", stdin);   
    freopen("lepus.out", "w", stdout); 
    int n; cin >> n;
    string s; cin >> s;
    vi dp(n, -1);
    dp[0] = 0;

    FOR(i,0,n){
        if(dp[i] == -1) continue;
        // dar um passo
        if(i+1 <n && s[i+1]!= 'w'){
            int grama;
            if(s[i+1] == '.') grama =0;
            else grama = 1;
            dp[i+1] = max(dp[i+1], dp[i] + grama);
        }

        //3 passos
        if(i+3 < n && s[i+3]!= 'w'){
            int grama;
            if(s[i+3] == '.') grama =0;
            else grama = 1;
            dp[i+3] = max(dp[i+3], dp[i]  + grama);
            
        }
        
        //5 passos
        if(i+5 < n && s[i+5]!= 'w'){
            int grama;
            if(s[i+5] == '.') grama =0;
            else grama = 1;
            dp[i +5] = max(dp[i+5], dp[i]  +grama);
        }
    }
    // FOR(i,1,n+1) deb(dp[i]);
    cout << dp[n-1] << endl;
    
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
