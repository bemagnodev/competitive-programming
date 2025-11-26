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
using pii = pair<ll, int>;
using pll = pair<ll, ll>;
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;
const int MAXN = 1e5+5;
vector<vector<tuple<int, ll , ll>>> adj(MAXN); // a :(b,x ,y) = a -> b com x abertos e y fechados
vector<ll> dist(MAXN, INF);
vector<bool> processed(MAXN, false);
ll t;


void dijkstra(int start_node) {
    priority_queue<pii> pq; //max-heap:  {-distância, nó}

    dist[start_node] = t;
    pq.push({-t, start_node});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) continue;
        processed[u] = true;

        //iterar pelos vizunhos de u
        for (auto& edge : adj[u]) {
            int v = get<0>(edge);
            ll x = get<1>(edge);
            ll y = get<2>(edge);

            ll espera =(x + y) - (dist[u] %(x+y)); //peso (u -> v)
            
            if(dist[u] %(x+y) <x ) espera = 0;
        
            if (dist[u] + espera < dist[v]) {
                dist[v] = dist[u] + espera;
                pq.push({-dist[v], v});
            }
        }
    }
}


void solve() {
    int n,m; cin >> n >> m >>t;

    FOR(i,0,m){
        int a, b; ll x,y; cin >> a >> b >> x >> y;
        adj[a].push_back({b,x,y});
        adj[b].push_back({a,x,y});
    }
    dijkstra(1);
    // FOR(i,1, n+1) deb(dist[i]);
    cout << dist[n] << endl;
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
