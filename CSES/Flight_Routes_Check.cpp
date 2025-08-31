#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<bool>& visitado, vector<vector<int>>&  adj){
    visitado[u] = true; 

    for(int v: adj[u]){// todos os vizinhos (v) de u
        if(!visitado[v]) dfs(v, visitado, adj);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int  n; cin >> n;
    int m; cin >> m;

    vector<vector<int>> adj(n+1);
    vector<bool> visitado(n+1, false);



    for(int i = 1; i< m+1; i++){
        int j; cin >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);

    }
    int count = 0;

    int u1, u2;
    for(int i = 1; i< n+1; i++){
        if(!visitado[i]){
            count++;
            if(i == 0) u1 = i+1;
            if(i == 1) u2 = i+1;
            dfs(i, visitado, adj);
        }
    }
    if (count > 1){
        cout << "NO" <<endl;
        cout << u1 << " " << u2 << endl;
    }
    else{
        cout << "YES" << endl;
    }

    return 0;
}