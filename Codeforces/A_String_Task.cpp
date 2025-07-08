#include <bits/stdc++.h>

using namespace std;

bool eh_vogal(char c){
    if (c == 'a'|| c == 'e' || c=='i' || c=='o'|| c=='u'|| c=='y' ){
        return true;
    }
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    string s; cin >> s;
    string resultado;

    for(char c : s){
        c = tolower(c);
        if(!eh_vogal(c)){ //se consoante
            resultado += '.';
            resultado += c;
        }
    }

    cout << resultado <<endl;


    //retirar vogais

    //antes da vogais inserir '.'

    //consoantes -> CONSOANTE
     
    return 0;


}
