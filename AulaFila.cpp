#include <iostream>
using namespace std;

#define MAX 10
int enfileirar(int fila[], int &ffila, int valor);
int desenfileirar(int fila[], int &ifila, int ffila, int &valor);
int main(void) {

    // Declarando uma fila
    int fila[MAX];
    int ifila = 0;
    int ffila = -1;

    int i, valor;

    do {
        cout << "Digite um numero: ";
        cin >> valor;
        if (valor > 0) enfileirar(fila, ffila, valor);
    } while( valor > 0);

    while(desenfileirar(fila, ifila, ffila, valor) == 0) {
        cout << valor << endl;
    }
}

// Retorna 0 em caso de sucesso e 1 em caso de fila cheia
int enfileirar(int fila[], int &ffila, int valor) {
    // Verificar se a fila está cheia
    if (ffila >= MAX-1) return 1;
    // Se não estiver
    // Incrementar a posição final
    ffila = ffila + 1;
    // Guardar o valor na posição final
    fila[ffila] = valor;
    // Indica sucesso
    return 0;
}

int desenfileirar(int fila[], int &ifila, int ffila, int &valor) {
    // Verificar se a fila tá vazia (e retornar erro se sim)
    if (ffila < ifila) return 1;
    // Ler o elemento do inicio da fila
    valor = fila[ifila];
    // Atualizar o inicio da fila
    ifila = ifila + 1;
    // Retornar sucesso
    return 0;
}