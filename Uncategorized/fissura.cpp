#include <bits/stdc++.h>
using namespace std;

bool dentro( int i, int j, int n, vector<string> & matriz){
    if (i >= 0 && i<n && j>= 0 && j<n && matriz[i][j] != '*'){ //dentro da matriz
        return true;
    }
    return false;

}

void dfs(int f, int i, int j, int n, vector<string> & matriz){
    int forca = f + 48;
    matriz[i][j] = '*'; //marca como visitado
    //verificar os adjacentes
    if(dentro(i,j+1,n, matriz)) { //direita
        if (matriz[i][j+1] <= forca) dfs(f, i, j+1, n, matriz);
    } 
    if(dentro(i,j-1,n, matriz)) { //esquerda
        if (matriz[i][j-1] <= forca) dfs(f, i, j-1, n, matriz);
    } 
    if(dentro(i+1,j,n, matriz)) { //baixo
        if (matriz[i+1][j] <= forca) dfs(f, i+1, j, n, matriz);
    } 
    if(dentro(i-1,j,n, matriz)) { //cima
        if (matriz[i-1][j] <= forca) dfs(f, i-1, j, n, matriz);
    } 
    
}

int main(){
    // recebe n -> linhas / colunas
    int n; cin >> n;
    //recebe f -> força
    int f; cin >> f;
    //recebe matriz vector<string> matriz(n)
    vector<string> matriz(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        matriz[i] = s;

    }


    //se matriz[0][0] <= f
    //chama a dfs para [0][0]
    if (matriz[0][0] <= f+48){
        dfs(f, 0, 0, n, matriz);
        for(int i =0; i <n; i++){
            cout << matriz[i] << "\n";
        }
    }
        //se não printa matriz
    else {
        for(int i =0; i <n; i++){
            cout << matriz[i] << "\n";
        }
    }
    

    return 0;
}