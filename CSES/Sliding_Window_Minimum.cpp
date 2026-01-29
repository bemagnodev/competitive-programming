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
const int INF = 1e9+5;
const ll INFLL = 4e18;

void solve() {
    int n, k; cin >> n >> k;
    int x; ll a, b, c; cin >> x >> a >> b >> c;
    vi v (n);
    v[0]= x;

    FOR(i,1,n){
        v[i] = (v[i-1]*a +b)%c;
    }
    deque<int> dq;

    ll ans = 0;
    int l = 0;
    FOR(r,0,n){
        if(!dq.empty() && dq.front() < l ) dq.pop_front();

        while(!dq.empty() && v[dq.back()] >= v[r]){
            dq.pop_back();
        }

        dq.push_back(r);


        if(r-l == k-1){
            ans ^= v[dq.front()];
            l++;
        }
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
