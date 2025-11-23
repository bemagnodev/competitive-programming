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
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;
const int MAXN = 2e5+5;

vector<pii> adj[MAXN]; // (peso, v)


void dijkstra(int start_node, vector<ll> &dist) {
        vector<bool> processed(MAXN, false);
		priority_queue<pii> pq; //max-heap:  {-distância, nó}

		dist[start_node] = 0;
		pq.push({0LL, start_node});

		while (!pq.empty()) {
			int u = pq.top().second;
			pq.pop();

			if (processed[u]) continue;
			processed[u] = true;

			//iterar pelos vizunhos de u
			for (auto& edge : adj[u]) {
				ll weight = edge.first;  //peso (u -> v)
				int v = edge.second;

				if (dist[u] + weight < dist[v]) {
					dist[v] = dist[u] + weight;
					pq.push({-dist[v], v});
				}
			}
		}
	}



void solve() {
    int n,m,x; cin >> n>>m>>x;
    FOR(i,0,m){
        int u,v; ll w; cin >> u >> v >>w;
        adj[u].push_back( {w,v});
        adj[v].push_back( {w,u});

    }

    vi friends(x);
    FOR(i,0,x) cin >> friends[i];
    
    vector<ll> dist1(n+1, INF), distN(n+1, INF);

    dijkstra(1, dist1);
    dijkstra(n, distN);
    
    ll ans = INF;
    for (int f : friends) {
        ans = min(ans, dist1[f] + distN[f]);
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
