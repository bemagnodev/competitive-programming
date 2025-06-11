#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cria set de char
    set<char> letras_unicas;
    //recebe mensagem [o(1)]
    string s; cin >> s;

    //itera pela mensagem [o(n)]
    for(char letra : s){
        //adiciona caracteres no map
        letras_unicas.insert(letra);
    }
     
    // retorna total de elementos no set
    int lentgh = letras_unicas.size();
    if (lentgh % 2 ==0){
        cout << "CHAT WITH HER!"<< endl;
    }
    else{
       cout << "IGNORE HIM!";
    }


    return 0;
}