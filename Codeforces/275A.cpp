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
    vector<vi>  m(3, vi(3,0)), ans(3, vi(3,1));
    FOR(i, 0 , 3){
        FOR(j,0,3){
            int x; cin >> x;
            // deb(x);
            m[i][j]= x;
            ans[i][j]+= x;
            //l
            if(j-1 >=0) ans[i][j-1] +=x;
            //r
            if(j+1 <3) ans[i][j+1] +=x;
            //t
            if(i-1>=0) ans[i-1][j] +=x;
            //b
            if(i+1 <3) ans[i+1][j] +=x;
         
        }
    }

    FOR(i, 0 , 3){
        FOR(j,0,3){
             cout << ans[i][j] %2;
        }
        cout << endl;
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
