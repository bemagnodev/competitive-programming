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
ll fast_exp(ll b, ll e){
    ll r = 1;
    b %= MOD;
    while(e >0){
        if(e % 2 ==1){
            r = (r * b) % MOD;
        }
        b =( b *b) %MOD;
        e/=2;
    }
    return r; 
}

ll inv(ll x){
    return fast_exp(x, MOD-2);
}

void solve() {
    ll a, b, n; cin >> a >> b >>n;
    //precalcular fatoriais
    vl fact(n+1);
    fact[0] =1;

    FOR(i, 1, n+1){
        fact[i]= fact[i-1]* (ll)i % MOD;
    }
    ll ans = 0;

    FOR(i, 0, n+1){
        //i as, j bs
        ll j = n-i;
        //é excelente?
        ll is_exc = j*b + i*a; //max 2 digitos
        bool ok = true;
        while(is_exc){
            if(is_exc%10 != a && is_exc%10 != b){
                ok = false;
            }
            is_exc/=10;
        }

       
        if(ok){ // é excelente
            //calcular n!i!j!
            ll C =(((fact[n] * inv( fact[i])) % MOD)  * inv( fact[j]))%MOD;
            ans =( ans + C) % MOD;
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
