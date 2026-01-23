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
using pli = pair<ll, int>;
#define mii map<int, int>

#define st first
#define nd second
const int MOD = 1e9 + 7;  
const ll INF = 1e18;

const int MAXN = 1e5+5;


void solve() {
    int n , m; cin >> n >> m;
    vector<vector<pli>> adj(n+1);

    vector<vl> dist(n+1, vl(2, INF));
    
    FOR(i,0,m){
        int a, b; ll w; cin >> a >> b >> w;
        adj[a].pb({w,b});
    }

        priority_queue<tuple<ll, int, int>> pq; //custo, vertice, estado

    	dist[1][1] = 0;
    	dist[1][0] = 0;
		pq.push({0LL, 1, 0});

		while (!pq.empty()) {
			auto top = pq.top();
            pq.pop();
            
            ll d = -get<0>(top);  
            int u = get<1>(top);
            int cupom = get<2>(top);


			if (d > dist[u][cupom]) continue;

			for (auto& edge : adj[u]) {
				ll w = edge.first;  //peso (u -> v)
				int v = edge.second;

				if (dist[u][cupom] + w < dist[v][cupom]) {
					dist[v][cupom] = dist[u][cupom] + w;
					pq.push(make_tuple(-dist[v][cupom], v, cupom));
				}

                if (cupom == 0) {
                    ll desconto = w / 2;
                    if (dist[u][0] + desconto < dist[v][1]) {
                        dist[v][1] = dist[u][0] + desconto;
                        pq.push(make_tuple(-dist[v][1], v, 1));
                    }
            }
			}
		}
	
    cout << dist[n][1] << endl;
}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
