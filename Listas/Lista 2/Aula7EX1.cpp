//Desenvolvido por Pedro Kourly
//Aula7 - Exercício 1

#include <iostream>
using namespace std;

#define MAX 10
int menu();
void enfileirar(int fila[], int &posF);
void desinfileirarTudo(int fila[], int &posF);
void listar(int fila[], int &posF);

main(void){

    int x; //var de escolha

    //declarando a fila
    int fila[MAX];
    int posF = 0; //posição final
    do
    {
       x = menu();
       switch (x){
        case 1:
            enfileirar(fila, posF);
            break;
        case 2:
            desinfileirarTudo(fila, posF);
            break;
        case 3:
            listar(fila, posF);
            break;
        case 4:
            cout << "Obrigado por usar o programa!";
            break; 
        default:
            cout << endl << "Opcao invalida, tente novamente." << endl;
            break;
       }
    } while (x != 4);
    
}

int menu(){
    int i;
    cout << endl << "-=-=-=-=-=-=MENU=-=-=-=-=-=-" << endl << "[1] - Enfileirar um numero inteiro positivo" << endl << "[2] - Desenfileirar tudo, exibindo os multiplos de 5" << endl << "[3] - Exibir os valores da fila" << endl << "[4] - Terminar o programa" << endl;

    cin >> i;
    return i;
}

void enfileirar(int fila[], int &posF){
    int valor;
    cout << endl << "Digite o numero a ser inserido: ";
    cin >> valor;

    //verifica se a fila ta cheia
    if (posF >= MAX-1){
        cout << endl << "Fila cheia! Tente novamente." << endl;
        return;
    }
    //verifica se o numero é positivo
    if (valor < 0){
        cout << endl << "Valor negativo! Tente novamente." << endl;
        return;
    }
    fila[posF] = valor;
    posF++;
}

void desinfileirarTudo(int fila[], int &posF){
    //verifica se a fila está vazia
    if(posF < 1) {
        cout << endl << "Fila vazia! Tente novamente." << endl;
        return;
    }
    //Mostra os multiplos de 5
    cout << endl;
    for (int i = 0; i < posF; i++){
        if(fila[i] % 5 == 0){
            cout << "fila[" << i << "]" << " = " << fila[i] << endl;
        } 
    }

    //Desinfileira tudo
    posF = 0;
    cout << endl << "Fila desenfileirada com sucesso!" << endl;
}


//EXTRA.. Função para listar tudo
void listar(int fila[], int &posF){
    cout << endl;
    for (int i = 0; i < posF; i++){
        cout << "fila[" << i << "]" << " = " << fila[i] << endl;
    }
}