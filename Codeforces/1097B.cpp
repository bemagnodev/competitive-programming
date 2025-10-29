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

void solve() {
    int n; cin >> n;
    vi a(n); FOR(i,0,n) cin >> a[i];

    //bitmask
    for(int mask = 0; mask <(1 <<n); mask ++){
        int soma = 0 ;
        
        FOR(i, 0, n){
            //olhar bit i
            if(mask & (1<< i)){//se ligado
                soma += a[i];
            } 
            else soma -= a[i];
        }

        if  (soma % 360 == 0){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
