#include <bits/stdc++.h>
using namespace std; 

using ll = long long;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

    // ENTRADAS
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    
    for( int i = 0; i < n; i++ ) cin >> a[i]; // ganhos como entregador de jornais
    for( int i = 0; i < n; i++ ) cin >> b[i];  // ganhos como segurança do shopping

    // CASO 1: lucro sem bônus  
    ll lucro_sem_bonus = 0;
    for (int i = 0; i < n; ++i) {
        lucro_sem_bonus += max(a[i], b[i]);
    }

    // CASO 2: lucro com bônus
    // seja D o dia em que júlio completa seus k dias no emprego b
    
    ll melhor_prefixo = 0; // soma dos ganhos até o dia D (antes de receber o bônus)
    vector<ll> melhor_sufixo(n + 1);  // melhor ganho possivel depois do dia D (após receber o bônus)

    ll lucro_com_bonus = 0;

    for( int i = n - 1; i >= 0; i-- ){
        //calcular sufixo escolhendo o maior entre a[i] e 2*b[i]
        melhor_sufixo[i] = melhor_sufixo[i + 1] + max( a[i], 2*b[i] ); 
    }
    
    //se k for 0, o bônus está ativado desde o primeiro dia
    if( k == 0 ){ 
        cout << melhor_sufixo[0] << endl; return 0;
    }

    // multiset = estrutura que guarda elementos ordenados, com repetição
    multiset<int> prejuizos; // guarda os prejuízos de escolher segurança ao invés de entregador (a[i]-b[i])


    //calcular melhor prefixo
    for( int i = 0; i < n; i++ ){
        // somar o ganho como segurança neste dia
        melhor_prefixo += b[i]; 

        // calcular o prejuízo de não trabalhar como entregador neste dia
        prejuizos.insert(a[i] - b[i]); 

        // enquanto não se apssou K dias, não podemos fomrar um prefixo válido
        if( i + 1 < k ) continue; 

        int maior_prejuizo =  *prejuizos.rbegin();

        // Se temos mais de K dias, retiramos o dia que menos compensa ser segurança
        if( prejuizos.size() > k && maior_prejuizo >= 0 ){
            melhor_prefixo += maior_prejuizo;
            prejuizos.erase(maior_prejuizo);
        }
        
        // lucro máximo considerando a maior soma:
        // prefixo até o dia i (antes do bônus)
        // sufixo a partir do dia i + 1 (após o bônus)
        lucro_com_bonus = max( lucro_com_bonus, melhor_prefixo + melhor_sufixo[i + 1] );
    }
    // Comparar lucro com bônus e lucro sem bônus (caso nunca compense completar K)
    cout << max(lucro_com_bonus, lucro_sem_bonus) << endl;
}