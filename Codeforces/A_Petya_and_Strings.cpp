#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    string s1 , s2;
    cin >> s1 >> s2;
    int resultado = 0; 
    //-1: segunda maior
    //1: primeira maior
    //0: iguais
    int tamanho = s1.size();

    for(int i= 0; i< tamanho; i++ ){
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);

        if(c1 > c2){ 
            resultado = 1;
        }
        else if (c2 > c1){
            resultado = -1;
        }
    }

    cout << resultado <<endl;


  
    return 0;
//

}
