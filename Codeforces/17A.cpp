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
const int MAXN = 1005;
vector<bool> is_prime(MAXN, true);
vi primes;
void sieve(int n){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i* i <= MAXN; i++){ // pq só vai até raiz de MAXN msm? nao pode ter um primo maior que a raiz de MAXN?
        if(is_prime[i]){
            for(int j = (ll)i *i; j<= MAXN; j+=i){
                is_prime[j]= false;
            }
        }
    }
    FOR(i,2,n+1){
        if(is_prime[i]) primes.push_back(i);
    }

}

void solve() {
    int n, k; cin >> n >>k;
    sieve(n);
    ll ans =0;
    FOR(i, 0, primes.size()-1){
        // cerr<< primes[i] << " ";
        // cerr<< endl;
        if(primes[i] ==7){
             if(is_prime[primes[i]+primes[i+1]+1]){
                // cerr << "masd" <<endl;
             }
        }
        if(is_prime[primes[i]+primes[i+1]+1] && primes[i]+primes[i+1]+1<=n){
            ans++;
            // cerr<< primes[i]+primes[i+1]+1 << " ";
        } 
    }
    // cerr<< endl << ans;
    if(ans >= k)cout << "YES\n";
    else cout << "NO\n";

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
