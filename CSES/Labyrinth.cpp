#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// variaveis globais
int n, m;
vector<string> mapa;
vector<vector<bool>> visitado;
//distancia
vector<vector<int>> distancia;
vector<vector<pair<int, int>>> pai;

int x_B, y_B;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

string consegue_terminar = "NO";

void bfs(int i_inicial, int j_inicial){
    queue<pair<int,int>> fila;
    //add na fila
    fila.push({i_inicial, j_inicial});
    //marca como visitado
    visitado[i_inicial][j_inicial] = true;
    //inicia distancia
    distancia[i_inicial][j_inicial]  = 0;

    while (!fila.empty())
    {
       int x_atual = fila.front().first;
       int y_atual = fila.front().second;
       //tira da fila
       fila.pop();
       //iterar pelos vizinhos
       for(int i =0; i < 4; i++){
           int x_vizinho = x_atual + dr[i];
           int y_vizinho = y_atual + dc[i];

            
            //se for caminho (.) e dentro da borda e nao visitado
                //marcar como visitado
                //add na queue
                //distancia ++
            if (x_vizinho >=0 && x_vizinho < n && y_vizinho >=0 && y_vizinho < m ){ // dentro do mapa
                if (mapa[x_vizinho][y_vizinho]== '.'&& visitado[x_vizinho][y_vizinho] == false){
                    visitado[x_vizinho][y_vizinho] = true;
                    fila.push({x_vizinho, y_vizinho});
                    //atualiza distancia
                    distancia[x_vizinho][y_vizinho] = distancia[x_atual][y_atual] +1;
                    
                    //atualiza //pai
                    pai[x_vizinho][y_vizinho] = {x_atual, y_atual};
                }
                else if(mapa[x_vizinho][y_vizinho]== 'B') {
                    x_B = x_vizinho;
                    y_B = y_vizinho;
                    visitado[x_vizinho][y_vizinho] = true;
                    pai[x_vizinho][y_vizinho] = {x_atual, y_atual};
                    distancia[x_vizinho][y_vizinho] = distancia[x_atual][y_atual] +1;
                    consegue_terminar = "YES";
                    return;

                }
            }
        }
    }
    

}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> n >> m;
    mapa.resize(n);
    visitado.resize(n, vector<bool>(m, false));
    distancia.resize(n, vector<int>(m, -1));
    pai.resize(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> ponto_partida;

    for( int i = 0; i < n; i++){
        cin >> mapa[i];  
    }

    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            if (mapa[i][j]== 'A') {
                ponto_partida.first = i;
                ponto_partida.second = j;
            }
        }
    }


    bfs(ponto_partida.first, ponto_partida.second);
    
    cout << consegue_terminar<< endl;

    if (consegue_terminar == "YES"){
        
        string caminho_reverso = "";
        pair<int, int> celula_atual = {x_B, y_B};
    
        while (celula_atual.first != ponto_partida.first || celula_atual.second != ponto_partida.second) {
            pair<int, int> p = pai[celula_atual.first][celula_atual.second];
            if (p == make_pair(-1,-1)) break; 

            if (p.first == celula_atual.first + 1) caminho_reverso += 'U';
            else if (p.first == celula_atual.first - 1) caminho_reverso += 'D';
            else if (p.second == celula_atual.second + 1) caminho_reverso += 'L';
            else if (p.second == celula_atual.second - 1) caminho_reverso += 'R';
    
    
            celula_atual = p;
        }
        reverse(caminho_reverso.begin(), caminho_reverso.end());
        int menor_distancia = distancia[x_B][y_B];
        cout << menor_distancia << endl;
        cout <<  caminho_reverso<< endl;
    }

    
    return 0;

}
