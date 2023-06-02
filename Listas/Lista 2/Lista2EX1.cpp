//Desenvolvido por Pedro Kourly
//Lista 2 - Exercício 1

#include <iostream>
using namespace std;

int menu();

main(void){
    int x;
    do
    {
       x = menu();
       switch (x)
       {
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
    cout << "-=-=-=-=-=-=MENU=-=-=-=-=-=-" << endl << "[1] - Enfileirar um numero inteiro positivo" << endl << "[2] - Desenfileirar um numero e imprimir o seu dobro" << endl << "[3] - Desenfileirar tudo, exibindo os valores sem alteracoes" << endl << "[4] - Terminar o programa" << endl;

    cin >> i;
    return i;
}