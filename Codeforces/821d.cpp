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

const int MAXN = 1e5+5;
vector<bool> visted(MAXN, false);
vl dist(MAXN, INF);
vector<vector<pii>> adj(MAXN);


void dijkstra(int strart_node){
    priority_queue<pii> pq;
    dist[strart_node] = 0;
    // last[strart_node] =?
    pq.push({0LL,strart_node});


    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(visted[u]) continue;
        visted[u] = true;

        for(auto& edge : adj[u]){
            ll w = edge.first;
            int v = edge.second;

            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+ w;
                pq.push({-dist[v], v});
            }
        }

    }

}


void solve() {
    int n,m,k; cin >> n >>m >>k;
    FOR(i,0,k){
        int x, y; cin >>x >> y;
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
