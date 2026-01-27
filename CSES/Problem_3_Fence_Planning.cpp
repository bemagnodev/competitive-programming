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
const int INF = 1e9+5;

struct Cow { int x; int y;};
void solve() {
    int n ,m ; cin >> n >>m ;
    vector<Cow> cows(n);
    vector<vi> adj(n);

    FOR(i,0,n){
        cin >> cows[i].x >> cows[i].y;
    }

    FOR(i,0,m){
        int a, b; cin >> a>> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int t, b, l, r; 

    vi visited(n,0);
    auto dfs =[&](auto&& self, int u)-> void{
        visited[u] = 1;
        int x = cows[u].x;
        int y = cows[u].y;
         t = max(y, t);
         r = max(x, r);
         b = min(y, b);
         l = min(x, l);

        for(int v: adj[u]){
            if(!visited[v]){
                self(self, v);
            }
        }
    };
    ll ans = INF;


    FOR(i,0,n){
        if(!visited[i]){
            t = -1, r = -1, l = INF, b = INF;
            dfs(dfs, i);

            ll h = abs(t-b);
            ll base = abs(r-l);
            ll p = 2*(h+base);
            ans = min (ans, p);

        }
    }
    cout << ans << endl;

}

int main() {
    fastio;
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
