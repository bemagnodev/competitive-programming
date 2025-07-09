#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int q; cin >> q;

    map<string , string> respostas; // original: final
    map<string , string> dono_original; // novo: ori0ginal
    int alteracoes = 0;

    for( int i = 0; i < q; i++){
        string velho, novo;
        cin >> velho >> novo;
        //atualizar maps
        //velho é original?
        if(dono_original.count(velho)){ //nome velho da requisição é original?
            //não é original
            //atualiza dono
            string novo_dono = dono_original[velho];
            dono_original[novo] = novo_dono;

            //atualiza respostas
            respostas[novo_dono] = novo;
            
        }    
        else{ //é original
            //adicionar ao dono original
            dono_original[novo] = velho; //novo : velho(original)
            //atualiza respostas
            respostas[velho] = novo;
            //atualizar n de alterações
            alteracoes++;
        } 
    }

    //resposta
    cout << alteracoes << endl;
    for (auto resposta : respostas){
        cout << resposta.first <<" " << resposta.second << endl;
    }

    return 0;


}
