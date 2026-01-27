#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // Necessário para std::clamp

using namespace std;

int main() {
    cout << "Testando versao do compilador...\n";

    // TESTE 1: Structured Binding (O que estava dando erro no seu BFS)
    // Isso só compila com -std=c++17 ou superior
    pair<int, string> aluno = {1, "Bernardo"};
    auto [id, nome] = aluno; 

    // TESTE 2: std::clamp (Recurso muito útil para geometria em CP)
    // Limita um valor entre um mínimo e máximo. Ex: clamp(valor, min, max)
    int valor = 100;
    int limitado = std::clamp(valor, 0, 50); // Deve virar 50

    cout << "\n--------------------------------------------------\n";
    cout << "✅ SUCESSO! O C++17 esta ATIVO e configurado.\n";
    cout << "--------------------------------------------------\n";
    cout << "Teste de Binding: ID=" << id << ", Nome=" << nome << "\n";
    cout << "Teste de Clamp: " << limitado << "\n";
    cout << "Versao do Padrao C++: " << __cplusplus << "\n";

    return 0;
}