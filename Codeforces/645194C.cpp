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

const int MAXN = 105;
vector<vector<pii>> adj(MAXN); //distancia, nó

void dijkistra(int start_node,vector<ll>& dist,vector<bool>& processed   ){
    priority_queue<pii> pq; //distancia, nó
    dist[start_node] = 0;
    pq.push({0, start_node});

    while(!pq.empty()){
        int u =  pq.top().second;
        pq.pop();

        if(processed[u])continue;
        processed[u] = true;

        for(auto &viz : adj[u]){
            ll w = viz.first;
            int v = viz.second;
            
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u] +w;
                pq.push({-dist[v], v});
            }

        }
    }
}

void solve() {
    int n, m, q; cin >> n >> m >> q;
    FOR(i,0,m){
        int x,y,d; cin >> x >> y >> d;
        double h; cin >> h;
        if( h== 0|| h*4.0 >= 5.0*1.82){
            adj[x].push_back({d, y});
            adj[y].push_back({d, x});
        }
    }
    int origem =1;
    FOR(i,0,q){
        int destino; cin >> destino;
        vector<ll> dist(MAXN, INF);
        vector<bool> processed(MAXN, false);
        dijkistra(origem, dist, processed);
        
        if(dist[destino] == INF){
            cout << -1 << endl;
            continue;
        }
        origem = destino;
        cout << dist[destino] << endl;
        

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
