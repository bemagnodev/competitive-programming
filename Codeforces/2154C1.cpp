'#include <bits/stdc++.h>
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


const int MAXN = 2e5 + 5;
vector<bool> fatores_vistos(MAXN,false);
int min_prime[MAXN]; 
void sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (min_prime[i] == 0) {
        for (long long j = 1LL * i; j <= n; j += i) {
            if (min_prime[j] == 0) min_prime[j] = i;
         }
        }
    }
}
set<int> factorize(int k) {
    set<int> factors;
    if (k <= 1) return factors;
    while (k > 1) {
        factors.insert(min_prime[k]);
        k /= min_prime[k];
    }
    return factors;
}

void solve() {
    int n; cin >> n;
    vi a(n); FOR(i, 0, n) cin >> a[i];
    vi b(n); FOR(i, 0, n) cin >> b[i];
    ll ans =0;

    bool dois = false;
    int pares =0 , impares = 0;
    vi fatores_atuais;

    FOR(i, 0, n) {
        int x = a[i];
        if(x %2 == 0) pares++;
        if(x %2 != 0) impares++;
        set<int> s = factorize(x);
        for(auto y : s){
            if(fatores_vistos[y]){
                dois = true;
                break;
            }
            fatores_vistos[y]= true;
        }
        
        if (!dois) {
                for (int p : s) {
                    if (!fatores_vistos[p]) {
                        fatores_vistos[p] = true;
                        fatores_atuais.push_back(p);
                    }
                }
            }
    }


    if(dois){
        cout<< 0 << endl;
    }
    else{
        if(pares && impares){
            cout<< 1 << endl;
        }
        else if(!pares && impares){
            cout<< 2 << endl;
        }

    }
    for (int p : fatores_atuais) {
        fatores_vistos[p] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    cin >> t;  
    sieve(MAXN);

    while (t--) {
        solve();  
    }

    return 0;
}
'