#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int H, P, F, D; 
    cin >> H >> P>> F>> D;
    string resposta;
    int i = F;
    //antihorario
    if (D==-1){
        while(true){
            if(i == P){
                resposta =  "S";
                break;
                
            }
            else if (i == H){
                resposta =  "N";
                break;
            }
            if(i==15) i=0;
            else i++;
        }
    }

    //horario
     if (D==1){
        while(true){
            if(i == P){
                resposta =  "S";
                break;
                
            }
            else if (i == H){
                resposta =  "N";
                break;
            }
            if(i==0) i=15;
            else i--;
        }
    }

           
    cout <<resposta<< endl;
    
    return 0;

}
