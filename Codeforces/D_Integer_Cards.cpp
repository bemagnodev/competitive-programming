#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    long long n, m;
    cin >> n >> m;
    map<int, int> cartas;


    for( int i = 0; i < n; i++){
        int k; cin >> k ;
        cartas[k]++;

    }
    //recener operações e guardalas num map <valor(c), qtde(b)> organizados pelos valor(c) crescente
    for( int i = 0; i < m; i++){ 
         int total_trocas, valor_troca;
         cin >> total_trocas >> valor_troca;
        cartas[valor_troca] += total_trocas;

         }


    long long soma_total = 0;
    long long cartas_restantes = n; 

    for(auto it = cartas.rbegin(); it !=  cartas.rend(); it++ ){// iterar reversamente pelo map (maior para o menor valor)
        //comparar valor 
        long long valor_carta = (*it).first;
        long long qtde_carta = (*it).second;
        long long pegar_agora =  min(cartas_restantes, qtde_carta);// para nao passar do maximo
        soma_total += valor_carta * pegar_agora;

        cartas_restantes -= pegar_agora;

        if (cartas_restantes == 0) break;
    }

    


    cout << soma_total << endl;

    return 0;


}
