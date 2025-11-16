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

bool is_prime(int x){
    if(x<2) return false;
    for(int i =2; i*i<= x; i++){
        if(x%i == 0) return false;
    }
    return true;
}

void solve() {
    int n, m; cin >> n >>m;
    // deb(is_prime(4));
    if(is_prime(n) && is_prime(m)){
        FOR(i,n+1, m){
            if(is_prime(i)){
                // deb(i);
                cout <<"NO\n";
                return;
            }
        }
        cout <<"YES\n";
        return;
    }
    cout <<"NO\n";
    return;


}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
