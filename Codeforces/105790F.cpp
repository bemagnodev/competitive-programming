#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define mii map<int, int>
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) (int)(x).size()
#define ins insert
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
const int MOD = 998244353;
const int MAXN = 1e3+5;
const ll INF = 4e18;
#define deb(k) cerr << #k << ": " << k << "\n";



void solve(){
    int n,k,x; cin >> n >> k >> x;
    vi s(n), e(n);
    FOR(i,0,n){
        cin >> s[i] >> e[i];
    }
    vll dp(n+1,-INF);
    // dp[i] = maximo de energia para concluir os primeiros i niveis
    dp[0] = 0;
    FOR(i,0,n){
        dp[i+1] = max(dp[i]+(e[i]-s[i]), dp[i+1]);
        int idx = min(n,i+k);
        dp[idx] = max(dp[i]-x, dp[idx]);
    }
    cout << max(dp[n],0LL) << "\n";
    
   
}

 
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    // int t; cin >> t;
    // while(t--)
    solve();
    return 0;
}

