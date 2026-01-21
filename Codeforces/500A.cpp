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
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;

void solve() {
    int n, t; cin >> n >> t;
    vector<vi> adj(n+1);
    FOR(i,1,n){
        int x; cin >> x;
        adj[i].pb(i+x);
    }
    vi visited(n+1, 0);

    auto dfs = [&](auto&& self, int u)->void{
        visited[u]= 1;
        for(int v: adj[u]){
            if(!visited[v]){
                self(self, v);
            }
        }
    };

    dfs(dfs, 1);

    // FOR(i,0,n) deb(visited[i]);

    if(visited[t]) cout<< "YES\n";
    else cout<< "NO\n";
    

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
