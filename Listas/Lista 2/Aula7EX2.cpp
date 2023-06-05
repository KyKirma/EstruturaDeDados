//Desenvolvido por Pedro Kourly
//Aula7 - Exercício 2

#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

void enfileirarChar(queue<char>& fila, string seq);
void empilharChar(stack<char>& pilha, queue<char>& fila);
void listarF(queue<char> fila);
void listarP(stack<char> pilha);

main(void){
    //Declarando a fila e a sequencia de caracteres
    queue<char> filaChar;
    stack<char> pilhaChar;
    string seq;

    cout << "Digite a sequencia de caracteres: ";
    cin >> seq;

    enfileirarChar(filaChar, seq);
    listarF(filaChar);
    empilharChar(pilhaChar, filaChar);
    listarP(pilhaChar);

}

void enfileirarChar(queue<char>& fila, string seq){
    //enfileira todos os caracteres numa fila
    for (char c : seq){
        fila.push(c);
    }
}

void listarF(queue<char> fila){

    int i = 0;
    cout << endl << "Listando a fila: "<< endl;
    while(!fila.empty()){
        cout << "Elemento [" << i << "] = " << fila.front() << endl;
        fila.pop();
        i++;
    }
    cout << endl;
}

void listarP(stack<char> pilha){
    int i = 0;
    cout << endl << "Desempilhando com suas devidas alterações:" << endl;
    while(!pilha.empty()){
        cout << "Elemento [" << i << "] = " << pilha.top() << endl;
        pilha.pop();
        i++;
    }
    cout << endl;
}

void empilharChar(stack<char>& pilha, queue<char>& fila){
    //Empilha a filha de char, sem alterar a fila original
    while(!fila.empty()){
        //Veririca se o char é uma letra
        if(isalpha(fila.front())){
            //Se sim, deixa em maiusculo
            char upper = toupper(fila.front());
            //Depois, empilha
            pilha.push(upper);
            fila.pop();
        } else {
            pilha.push(fila.front());
            fila.pop();
        }
    }
}