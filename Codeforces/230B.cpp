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
const ll INF = 1e18;
const int MAXN = 1e6+5; // raiz de 10^12
vector<bool> eh_quadrado(MAXN, false);
vector<bool> eh_primo(MAXN, true);

void sieve(){
    eh_primo[0] = eh_primo[1] = false;
    for(int p =2; (ll)p*p <= MAXN; p++){ 
        if(eh_primo[p]){
             for (ll i = (ll)p * p; i < MAXN; i += p) {  
                eh_primo[i] = false;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    sieve();
    FOR(i,0,n){
        ll x; cin >> x;
        ll s = (ll)sqrt(x);
        if(s* s ==x &&  eh_primo[sqrt(x)]){ 
           cout << "YES\n";
           continue;
        }
        cout << "NO\n";
    }

    
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
