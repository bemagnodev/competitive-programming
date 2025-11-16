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

void solve() {
    int n, f; cin >> n >> f;
    vi discipulos(n);
    vi counts(1<<f , 0); //conta frequencia de cada combinação de respirações

    FOR(i,0,n){
        string s; cin >> s;
        int binario = 0;
        FOR(j,0,f){
            if(s[j] =='S'){
                binario += (1<< j);//2^j
            }
        }
        discipulos[i] = binario;
        counts[binario]++;
        // deb(discipulos[i]);
    }

    vi dp = counts;

    //iterar pelos bits
    FOR(i,0,f){
        //iterar pelas masks de traspra frente
        ROF(mask, 0 , (1<<f)){
            // se o bit i tiver desligado
            if(!( mask & (1<<i))){
                // adicionar dp[mask]+= mask com bit i ligado
                int mask_com_i_ligado = mask |(1<<i);
                dp[mask]+= dp[mask_com_i_ligado];
            }
        }
    }

    ll ans =0;

    FOR(mask,0,(1<<f)){
        int falta =  mask ^ ((1<< f)-1);
          if(falta == 0) {
            ans += (ll)counts[mask] * (dp[0] - 1);
        } else {
            ans += (ll)counts[mask] * dp[falta];
        }
    }
    cout << ans/2 << endl;
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
