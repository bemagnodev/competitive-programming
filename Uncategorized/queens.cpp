#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n = 5; // Tamanho do tabuleiro (5x5)

    // Vetores para marcar se há uma rainha na linha, coluna ou diagonal
    vector<int> info_linhas(n, 0);
    vector<int> info_colunas(n, 0);
    vector<int> info_diagonais_principais(2 * n - 1, 0);   // i - j fixo
    vector<int> info_diagonais_secundarias(2 * n - 1, 0);  // i + j fixo

    // Tabuleiro inicial preenchido com '.'
    vector<vector<char>> grid(n, vector<char>(n, '.'));

    // Percorre todas as posições do tabuleiro
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // Verifica se pode colocar uma rainha na posição (i, j)
            if (info_linhas[i] == 0 &&
                info_colunas[j] == 0 &&
                info_diagonais_principais[j - i + n - 1] == 0 &&
                info_diagonais_secundarias[j + i] == 0) {

                // Marca a posição com 'Q' e atualiza os vetores de controle
                grid[i][j] = 'Q';
                info_linhas[i] = 1;
                info_colunas[j] = 1;
                info_diagonais_principais[j - i + n - 1] = 1;
                info_diagonais_secundarias[j + i] = 1;

                // Este trecho tenta reverter a posição se a linha não foi preenchida
                if (j == n && info_linhas[i] == 0) {
                    // desfazer a última tentativa (não está implementado corretamente)
                    info_colunas[j] = 0;
                    info_diagonais_principais[j - i + n - 1] = 0;
                    info_diagonais_secundarias[j + i] = 0;
                    i--;
                }

                // Imprime o tabuleiro atual após colocar a rainha
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << grid[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
}
