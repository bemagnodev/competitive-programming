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
    int n; cin >> n;
    vi ans;
    int pot10 =1;
    while(n>0){
        if(n%10) ans.push_back((n%10)*pot10);
        n/=10;
        pot10*=10;
    }
    cout << ans.size() << endl;
    for(int i : ans) cout<< i << " ";
    cout << endl;
}

int main() {
    fastio;
    int t =1; 
    cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
