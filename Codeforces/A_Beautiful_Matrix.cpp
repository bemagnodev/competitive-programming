#include <bits/stdc++.h>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    //declarar matriz
    vector<vector<int>> matriz(5,vector<int>(5, 0));
    
    //declarar cordenadas do 1
    pair<int,int> coordenada_um;

    // receber matrix
    // verificar e guardar posição do 1 (x,y)
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int k; cin >> k;
            if( k == 1){
                matriz[i][j] = 1;
                coordenada_um.first = i;
                coordenada_um.second = j;
            }

        }
    }
    

    //calcular quantidade de movimentos para (x,y) -> ?(2,2)
    int moves = abs(coordenada_um.first -2) + abs(coordenada_um.second -2);

    cout << moves << endl;
    return 0;
}