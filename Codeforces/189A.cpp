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
const int INF = 1e7;

void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    //n = ax . by . cz
    vi dp(n+1, -1); // maximo de fitas que eu posso ter com comprimento i
    dp[0]=0;

    FOR(i,1,n+1){
        if(i - a >=0 && dp[i-a] != -1){
            dp[i] = max( dp[i], dp[i-a] +1);
        }
        if(i - b >=0 && dp[i-b] != -1){
            dp[i] = max( dp[i], dp[i-b] +1);
        }
        if(i - c >=0 && dp[i-c] != -1){
            dp[i] = max( dp[i], dp[i-c] +1);
        }
    }

    cout << dp[n]<< endl;
    // FOR(i,0,n+1) cerr << dp[i]<<" ";


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
