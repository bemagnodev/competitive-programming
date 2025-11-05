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
    int n, m ,  k; cin >> n >> m >> k;
    vi a(n);
    FOR(i,0,n) cin >> a[i];
    
    map<pii, int> bonus; // (x->y), bonus
    FOR(i,0,k) {
        int x, y, c; cin >> x>>y >> c;
        bonus[{x,y}] = c;
    }

    vector<vl> dp((1<<n), vl(n, 0));

    //base da dp (apenas um bit ativo (n casos para isso))
    FOR(i, 0 , n){
        dp[(1 << i)][i] = a[i];//mask de bit unico sendo seu unico bit o ultimo
    }

    //bitmask
    ll max_soma = 0;
    ll ans = 0;
    for(int mask = 1; mask < (1 << n); mask++){
        ll soma =0;
        // montar dp
        FOR(i, 0, n){
            //para cada bit i ativo em mask
            if(__builtin_popcount(mask) > m) continue;
            if(mask & (1 << i)){
                int prev_mask = (mask  ^ (1<<i)); //mask com bit i desativado
                //testar todos os j (bits ativos de prev) para encontrar max
                // int bits_prev = __builtin_popcount(prev_mask);
                FOR(j, 0, n){
                    if(!(prev_mask & (1<<j))){ // se o bit j de prev mask estiver inativo
                        continue;//ignora
                    }
                    dp[mask][i] = max(dp[prev_mask][j] + a[i] + bonus[{j+1,i+1}], dp[mask][i]);
                }
                
            }
        }
    }

    FOR(mask, 0, (1 << n)) {
    if (__builtin_popcount(mask) == m) {
        FOR(i, 0, n) {
            if (mask & (1 << i)) {  
                ans = max(ans, dp[mask][i]);
            }
        }
    }
}

    cout << ans << endl;

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
