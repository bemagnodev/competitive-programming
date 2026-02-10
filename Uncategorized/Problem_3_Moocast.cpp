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
    int n; cin >> n;
    vector<vi> adj(n);

    vector<vi> cows(n, vi(3));//x,y,p

    FOR(i,0,n){
        int x,y,p; cin >> x >> y >>p;
        cows[i][0] = x;
        cows[i][1] = y;
        cows[i][2] = p;
    }
    
    FOR(i,0,n-1){
        FOR(j, i+1, n){
            int x1 = cows[i][0];
            int  y1 = cows[i][1];
            int p1 =  cows[i][2];
            
            int x2 = cows[j][0];
            int y2 = cows[j][1];
            int p2 = cows[j][2];

            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);

            if(dx* dx + dy * dy <= p1* p1){
                adj[i].pb(j);
            }
            if(dx* dx + dy * dy <= p2* p2){
                adj[j].pb(i);
            }
        }
    }
    vi visited(n,0);

    auto dfs = [&](auto&& self, int u) -> void{
        visited[u] = 1;

        for(int v: adj[u]){
            if(!visited[v]){
                self(self, v);
            }
        }
    };
    int ans = 0;
    
    FOR(i,0,n){
        visited.assign(n,0);
        dfs(dfs,i);
        int total = 0;
        FOR(j,0,n){
            if(visited[j]) total++;
        }
        ans = max(ans, total);
    }

    cout << ans << "\n";


}

int main() {
    fastio;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
