#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Criar map registros<string, int> -> <nome, acessos>
    map<string, int> registros;

    //recebe n -> numero de requisições [O(1)]
    int n; cin >> n;
    //recebe n requerimentos (strings)  [O(n)]
    for(int i =0; i< n; i++){
        string nome; cin >> nome;
        //verifica existenia do nome atual no map [O( log n)] 
        if (registros.count(nome)){
            registros[nome] ++;
            cout << nome << registros[nome] << endl;
        }
        else {
            registros[nome] = 0;
            cout << "OK" << endl;
        }
        
            //se sim 
                //adicionar 1 ao valor
                //retorna nome+value
         
            //se não 
                    //adicionar no map com valor 0 
                    //retorna OK
    }
    return 0;
}