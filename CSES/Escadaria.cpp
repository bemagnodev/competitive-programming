#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // Entrada
    int n; cin >> n;
    vector<int> alturas(n);
    for(int i = 0; i < n; i++) cin >> alturas[i];

    // definir um valor seguro para infinito
    const ll INF = 2000000; 

    // Vetores para guardar os limites de cada lado
    vector<ll> limite_esquerda(n);
    vector<ll> limite_direita(n);

    // PASSO 1: calcular limites da esquerda para direita

    // caso base (degrau 0)
    if (alturas[0] == -1) 
        limite_esquerda[0] = INF; 
    else 
        limite_esquerda[0] = alturas[0];    

    // Restante dos degraus (1 até n-1)
    for (int i = 1; i < n; ++i) {
        ll limite_vizinho = limite_esquerda[i - 1] + 1; // um a mais do que a altura do degrau anterior
        ll limite_proprio; // não pode ser maior que sua própria altura, caso ela seja conhecida
        if (alturas[i] == -1) 
             limite_proprio = INF;
        else    
             limite_proprio = alturas[i]; 
        
        limite_esquerda[i] = min(limite_vizinho, limite_proprio);
    }

    // PASSO 2: calcular limites da direita para esquerda

    // Base (Degrau n-1)
    if (alturas[n - 1] == -1) {
        limite_direita[n - 1] = INF;
    } else {
        limite_direita[n - 1] = alturas[n - 1];
    }

    // Restante dos degraus (n-2 até 0)
    for (int i = n - 2; i >= 0; --i) {
        ll limite_vizinho = limite_direita[i + 1] + 1; // um a mais do que a altura do próximo degrau  
        ll limite_proprio; // não pode ser maior que sua própria altura, caso ela seja conhecida
        if (alturas[i] == -1) {
            limite_proprio = INF;
        } else {
            limite_proprio = alturas[i];
        }
        
        limite_direita[i] = min(limite_vizinho, limite_proprio);
    }

    // PASSO 3: Combinar os Limites 

    // A resposta final para o degrau i é o mínimo dos dois limites
    for (int i = 0; i < n; ++i) {
        ll altura_maxima = min(limite_esquerda[i], limite_direita[i]);
       cout << altura_maxima << " ";
    }
   cout << "\n";

    return 0;
}
