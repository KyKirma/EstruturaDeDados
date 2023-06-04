//Desenvolvido por Pedro Kourly
//Aula8 - Exercício 1

#include <iostream>
using namespace std;

#define MAX 10
int menu();
void enfileirar(int fila[], int &posF);
void desinfileirar(int fila[], int &posF);
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
            desinfileirar(fila, posF);
            break;
        case 3:
            desinfileirarTudo(fila, posF);
            break;
        case 4:
            listar(fila, posF);
            break;
        case 5:
            cout << "Obrigado por usar o programa!";
            break;
        default:
            cout << endl << "Opcao invalida, tente novamente." << endl;
            break;
       }
    } while (x != 5);
    
}

int menu(){
    int i;
    cout << endl << "-=-=-=-=-=-=MENU=-=-=-=-=-=-" << endl << "[1] - Enfileirar um numero inteiro positivo" << endl << "[2] - Desenfileirar um numero e imprimir o seu dobro" << endl << "[3] - Desenfileirar tudo, exibindo os valores sem alteracoes" << endl << "[4] - Exibir os valores da fila" << endl << "[5] - Terminar o programa" << endl;

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

void desinfileirar(int fila[], int &posF){
    //verifica se a fila está vazia
    if(posF < 1) {
        cout << endl << "Fila vazia! Tente novamente." << endl;
        return;
    }
    //variavel de manipulação de desinfileirar
    //Mostrar o dobro
    int val = fila[0];
    cout << endl << "-=Desinfileirando=-" << endl << "O valor da posicao[0] = " << val << endl << "Valor dobrado: " << (val * 2) << endl;

    //Desinfileirando
    
    for (int i = 0; i < posF; i++){
        fila[i] = fila[i + 1];
    }
    posF--;
}

void desinfileirarTudo(int fila[], int &posF){
    //verifica se a fila está vazia
    if(posF < 1) {
        cout << endl << "Fila vazia! Tente novamente." << endl;
        return;
    }
    //Mostra os valores da lista inteira
    cout << endl;
    for (int i = 0; i < posF; i++){
        cout << "fila[" << i << "]" << " = " << fila[i] << endl;
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