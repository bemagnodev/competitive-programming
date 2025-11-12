#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

const int MOD = 1e9 + 7;  
const int INF = 1005;
const int MAXN = 105;
vector<vi> adj(MAXN);
vi ciclo(MAXN, INF);

void bfs(int u, int orig, vi dist){
    queue<int> q;
    dist[u] = 0;
    q.push(u);

    while(!q.empty()){
        int atual = q.front();
        q.pop();
        
        for(int v: adj[atual]){
            if(dist[v] == -1){
                dist[v] = dist[atual] +1;
                q.push(v);

                // verifica se é um dos vizinhos originais != de u
                for(int v_orig : adj[orig]){
                    if(v_orig != u && v == v_orig){
                        ciclo[orig] = min(ciclo[orig], dist[v] +2);
                    }
                }
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >>m;
    FOR(i,0,m){
        int a ,b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //para cada vértice u chamar bfs para todos vizinhos v BFS(v, u)
    FOR(u, 1, n+1){
        if(adj[u].size() <= 1) continue; // nao da pra formar ciclo
        for(int v : adj[u]){
            vector<int> dist(n+1, -1);
            dist[u] = 0;
            bfs(v,u, dist);
        }
    }

    ll ans =0;
    FOR(i, 1, n+1){
        // cerr<< ciclo[i]<< " ";
        if(ciclo[i] == INF) ciclo[i]= 1;
        ans += ciclo[i] * i;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t =1; 
    // cin >> t;  

    while (t--) {
        solve();  
    }

    return 0;
}
