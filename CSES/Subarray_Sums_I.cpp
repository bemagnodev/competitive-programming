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
    int n,x ; cin >> n>> x;
    vl a(n), pref(n+1,0);
    FOR(i,0,n){
        cin >> a[i];
    } 
    
    ll ans = 0;
    ll soma = 0;
    int l = 0;
    
    FOR(r,0,n){
        soma += a[r];
        
        while(soma > x && l<=r){
            soma -=a[l];
            l++;
        }
        if(soma == x)ans++;
    }
    cout << ans << endl;

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
