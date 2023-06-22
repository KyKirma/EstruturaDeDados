#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numeroDecimal;
    cout << "Digite um número decimal: ";
    cin >> numeroDecimal;
    
    vector<int> binario = decimalParaBinario(numeroDecimal);
    
    cout << "O número binário correspondente é: ";
    for (int i = 0; i < binario.size(); i++) {
        cout << binario[i];
    }
    
    cout << endl;
    
    return 0;
}

vector<int> decimalParaBinario(int numero) {
    vector<int> binario;
    
    if (numero == 0) {
        binario.push_back(0);
    }
    else {
        while (numero != 0) {
            binario.push_back(numero % 2);
            numero /= 2;
        }
    }
    
    // Inverte o vetor para obter o resultado correto
    reverse(binario.begin(), binario.end());
    
    return binario;
}