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

void solve() {
    int n,m; cin >> n >> m;
    vector<vi> adj(n+1);
    FOR(i,0,m){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi color(n+1,-1);
    vi visited(n+1,0);
    FOR(i,1,n+1){
        if(!visited[i]){
            // bfs 
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            if(color[i] == -1) color[i] = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                // cor

                //viz
                for(int v : adj[u]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v] = 1;
                        color[v] = 3- color[u]; 
                    }
                    else{
                        if(color[v] == color[u]){
                            cout<< "IMPOSSIVEL"; return;
                        }
                    }
                }
            }
        }
    }
    vi um, dois;
    FOR(i,1,n+1){
        if(color[i] == 1) um.push_back(i);
        else if(color[i] == 2) dois.push_back(i);
    }
    cout << "POSSIVEL\n" << um.size() << " " << dois.size() << endl;
    for(int x : um) cout << x<< " ";
    cout << endl;
    for(int x : dois) cout << x<< " ";
    cout << endl;

}

int main() {
    fastio;
    int t =1; 
    // cin >> t;  
    while (t--) 
        solve();  
    return 0;
}
