#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int restaurantes = 0;
void dfs(int no_atual, int pai, int n, int m, int gatos, vector<bool> &visitados, vector<vector<int>> &grafo, vector<int> &tem_gato){
    visitados[no_atual] = true; //marcar como visitado
    int qtde_vizinhos = grafo[no_atual].size();
    int novo_gatos;

    if(pai != 0 && grafo[no_atual].size() == 1){
        restaurantes ++;
    }
    
    for(int i = 0; i < qtde_vizinhos; i++){ //iterar pelos vizinhos
        int vizinho = grafo[no_atual][i];
        //atualiza numero de gatos
        if (tem_gato[vizinho]){
            novo_gatos = gatos +1;
        }
        else{ novo_gatos = 0;}

        if (vizinho != pai && !visitados[vizinho] && novo_gatos <= m){ //se vizinho diferente do pai e nao visitado
            //se for folha cont ++
            dfs(vizinho, no_atual, n, m ,novo_gatos, visitados, grafo, tem_gato);
        }        
            //dfs vizinho
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ll n, m; cin >> n >> m;

    vector<int> tem_gato(n+1, 0);

    vector<vector<int>> grafo(n+1, vector<int>(0));
    vector<bool> visitados(n+1, false);

    for( int i = 1; i <= n; i++){
        cin >> tem_gato[i];
    }

    for( int i = 1; i < n; i++){
        int no_origem , no_destino;
        cin >> no_origem >> no_destino;
        grafo[no_origem].push_back(no_destino);
        grafo[no_destino].push_back(no_origem);


    }

    //verifica se primeiro no tem gato
    int gatos_iniciais = tem_gato[1];
    dfs(1, 0, n, m, gatos_iniciais, visitados, grafo, tem_gato);


    cout << restaurantes<<  endl;

    return 0;

}
