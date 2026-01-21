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
    int n, m; cin >> n>>m;
    vector<vi> adj(n+1);
    vector<int> dist(n+1, -1);
    vector<int> pai(n+1);
    FOR(i,1,n) pai[i] = i;

    FOR(i,0,m){
        int a, b; cin >> a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    auto bfs = [&]( int s)->void{
        dist[s]=0;
        queue<int> q;
        q.push(s);

        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int v: adj[u]){
                if(dist[v]==-1){
                    dist[v] = dist[u]+1;
                    pai[v] = u;
                    q.push(v);
                }
            }
        }
    };

    bfs(1);
    if(dist[n]==-1){
        cout << "IMPOSSIBLE" <<endl;
        return;
    }
    cout << dist[n] +1<< endl;
    vi caminho;
    int atual = n;
    while(atual!= 1){
        caminho.pb(atual);
        atual = pai[atual];
    }

    cout << 1 << " ";
    ROF(i,0,caminho.size()){
        cout << caminho[i]<< " ";
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
