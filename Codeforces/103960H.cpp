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

struct Kosaraju {
    int n;
    vector<vector<int>> adj, rev_adj;
    vector<bool> visited;
    vector<int> order, component;
    vector<vector<int>> sccs;

    Kosaraju(int _n) : n(_n), adj(_n), rev_adj(_n), visited(_n), component(_n, -1) {}

    // Adiciona aresta direcionada u -> v
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    // Primeira DFS: gera a ordem de terminação (topo sort-like) no vetor order (funciona como uma stack)
    void dfs1(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) dfs1(v);
        }
        order.push_back(u);
    }

    // Segunda DFS: agrupa os nós no grafo transposto
    void dfs2(int u, int c) {
        visited[u] = true;
        component[u] = c;
        sccs.back().push_back(u);
        for (int v : rev_adj[u]) {
            if (!visited[v]) dfs2(v, c);
        }
    }

    // Função principal que orquestra o algoritmo
    void build() {
        fill(visited.begin(), visited.end(), false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs1(i);
        }

        reverse(order.begin(), order.end());
        fill(visited.begin(), visited.end(), false);

        int count = 0;
        for (int u : order) {
            if (!visited[u]) {
                sccs.push_back({});
                dfs2(u, count++);
            }
        }
    }
};

void solve() {
    int n, m; cin >> n>>m;
    Kosaraju g(n);
    FOR(i,0,m){
        int a,b; cin >> a >> b; a--;b--;
        g.add_edge(a, b);
    }
    g.build();
    int sccs = g.sccs.size();
    if(sccs == 1){
        cout << 0 << endl;
        return;
    } 

    vi out(sccs,0);
    vi in(sccs,0);


    FOR(u,0,n){
        for( int v : g.adj[u]){
            if(g.component[u] != g.component[v]){
                in[g.component[v]]++;
                out[g.component[u]]++;
            }
        }
    }
    int zero_out = 0, zero_in = 0;

    FOR(i,0,sccs){
        if(out[i] == 0) zero_out++;
        if(in[i] == 0) zero_in++;
    }

    cout << max(zero_in, zero_out)<<endl;

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
