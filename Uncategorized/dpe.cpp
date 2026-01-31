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
    int n; ll W; cin >> n >>W;
    vl weight(n); vi value(n);
    int V = 0;
    FOR(i,0,n){
        cin  >> weight[i] >> value[i];
        V+= value[i];
    }
    vl dp(V+1,INFLL); // peso minimo necessario para alcançar o valor v
    dp[0]= 0;
    FOR(j,0,n){
        ll w = weight[j];
        int v = value[j];
        ROF(i,1,V+1){
            if(i-v >=0){
                dp[i] = min(dp[i], dp[i-v]+w);
            }
        }
    }
    

    ll mx = 0, ans =0;

    FOR(i,0,V+1){
        if(dp[i]<= W){
            ans =i;
        }
    }

    cout << ans<<"\n";


}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
