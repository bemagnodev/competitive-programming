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

ll exp (ll b, ll e){
    ll res = 1;
    while(e){
        if(e&1) res=(res*b)%MOD;
        b=(b*b)%MOD;
        e>>= 1;
    }
    return res;
}

ll exp (int b, int e){
    ll res = 1;
    while(e){
        if(e&1) res = (res*b)%MOD;
        b = (b*b)%MOD;
        e>>=1;
    }
    return res;
}

void solve() {
    ll a,b; cin >> a >> b;
    cout << exp(a,b) << "\n";


}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
