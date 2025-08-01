#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dr[] = {0, 0, 1, -1}; // Deslocamento na linha (d-row)
int dc[] = {1, -1, 0, 0}; // Deslocamento na coluna (d-col)

void bfs(int i, int j, vector<string> &tabuleiro, int n, int m){
    //1. criar fia e iniciala
    queue<pair<int,int>> fila;
    fila.push({i,j});
    tabuleiro[i][j] = 'B';
    
    //2 loop while
    while(!fila.empty()){
        int linha_atual = fila.front().first;
        int coluna_atual = fila.front().second;
        fila.pop(); 

        char cor_atual = tabuleiro[linha_atual][coluna_atual];
        char cor_oposta = (cor_atual == 'B'? 'W' : 'B');


        //checar cada vizinhos
        for(int i =0; i < 4 ; i++){
            int x_vizinho = linha_atual + dr[i];
            int y_vizinho = coluna_atual + dc[i];

            //verificação borda
            if(x_vizinho >= 0 && x_vizinho < n && y_vizinho >= 0 && y_vizinho < m  && tabuleiro[x_vizinho][y_vizinho] == '.'){
                tabuleiro[x_vizinho][y_vizinho] = cor_oposta;

                fila.push({x_vizinho, y_vizinho});

            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n, m; cin >> n >> m;

    vector<string> tabuleiro(n);
    vector<vector<bool>> visitados(n, vector<bool>(m, false));


    for( int i = 0; i < n; i++){
        cin >> tabuleiro[i];
    }
    
    //encontrar celula inicial
    int i_inicial, j_inicial;
    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            if( tabuleiro[i][j] == '.'){
                i_inicial = i;
                j_inicial = j;
                bfs(i_inicial, j_inicial, tabuleiro, n, m);

            }
        }
    }
    // cout << "i inicial: " << i_inicial << " j inicial: " << j_inicial <<endl;



    for( int i = 0; i < n; i++){
        cout << tabuleiro[i] << endl;
    }

    cout << endl;
    
    
    return 0;

}
