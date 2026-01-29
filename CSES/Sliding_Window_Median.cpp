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
    int n, k; cin >> n >> k;
    vi a(n); FOR(i,0,n) cin >> a[i];


    multiset<int> low, up;
    ll ans = 0;
    int l = 0;

    FOR(r,0,n){
        if (low.empty() || a[r] <= *low.rbegin()) low.insert(a[r]);
        else up.insert(a[r]);


        if(r>= k){
            // remover a[l]
            auto it = low.find(a[l-1]); 
            if (it != low.end()) 
                low.erase(it);
            else up.erase(up.find(a[l-1]));
        }
        

        while((int)low.size() > (k+1)/ 2){
            int maior_low  = *low.rbegin();
            up.insert(maior_low);
            low.erase(prev(low.end()));
        }

        while ((int)low.size() < (k + 1) / 2 && !up.empty()) {
            int menor_up  = *up.begin();
            low.insert(menor_up);
            up.erase(up.begin());
        }

        if(r-l == k-1){
            ans = *low.rbegin();
            cout << ans << " ";
            l++;
        }



    }
    cout << endl;

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
