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
    while(true){
        int n; cin >> n;
        if(n == 0)break;
        vi a(n);
        FOR(i,0,n) cin >> a[i];
        stack<int> p;
        bool pode = true;
        FOR(i,0,n-1){
            if(a[i] > a[i+1]){
                if(!p.empty() && p.top() < a[i]){
                    pode = false;
                    break;
                }
                p.push(a[i]);
            }
        }
        if(pode) cout << "yes\n";
        else cout <<"no\n";
        
    }

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
