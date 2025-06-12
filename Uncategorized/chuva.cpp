#include <bits/stdc++.h>
using namespace std;

int N, M;
string matriz[500];

void dfs(int i, int j){
    matriz[i][j] = 'o';

    if(i == N-1) return;

    if ( matriz[i+1][j] == '.') dfs(i+1, j);

    if ( matriz[i+1][j] == '#') {
        if(matriz[i][j+1] == '.') dfs(i, j+1);
        if(matriz[i][j-1] == '.') dfs(i, j-1);
    }
}

int main(){
    cin >> N >> M;
    
    
    for (int i =0; i <N ; i++) cin >> matriz[i];
    
    for (int i =0; i <N ; i++) {
            if(matriz[0][i] == 'o') dfs(0,i);
    }

    for (int i =0; i <N ; i++) cout << matriz[i] << endl;

    return 0;
}