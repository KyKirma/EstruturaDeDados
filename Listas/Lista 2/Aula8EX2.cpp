//Desenvolvido por Pedro Kourly
//Aula7 - Exercício 2

#include <iostream>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

void enfileirarChar(queue<char>& filaA, queue<int>& filaB, string seq);
void listarF(queue<char> filaA, queue<int> filaB);

main(void){
    //Declarando as filas
    queue<char> filaA; // Apenas de letras
    queue<int> filaB; // Apenas de Numeros
    string seq;

    cout << "Digite a sequencia de caracteres: ";
    cin >> seq;

    enfileirarChar(filaA, filaB, seq);
    listarF(filaA, filaB);
}

void enfileirarChar(queue<char>& filaA, queue<int>& filaB, string seq){
    //enfileira todos os caracteres entre uma fila A e B
    for (char c : seq){
        //verifica se o char é uma letra
        if(isalpha(c)){
            //se sim, add a fila A
            filaA.push(c);

        //verifica se o char é um número
        } else if (isdigit(c)){
            //se sim, converta c para int
            filaB.push(c - '0');
        
        } //Se não for nenhum dos dois, não faz nada.
    }
}

void listarF(queue<char> filaA, queue<int> filaB){

    int i = 0;
    cout << endl << "Listando a fila A: "<< endl;
    while(!filaA.empty()){
        cout << "Elemento [" << i << "] = " << filaA.front() << endl;
        filaA.pop();
        i++;
    }
    cout << endl;

    i = 0;
    cout << endl << "Listando a fila B: "<< endl;
    while(!filaB.empty()){
        cout << "Elemento [" << i << "] = " << filaB.front() << endl;
        filaB.pop();
        i++;
    }
    cout << endl;
}