#include <iostream>
using namespace std;

void inserirSemRepetir(int v[], int x, int &pos, int max);

int main(void){
	//Declarando as variaveis
	int x, max, max2, i;
	int qnt = 0;

	cout << "Digite o tamanho maximo da primeira lista: ";
	cin >> max;
	
	cout << "Digite o tamanho maximo da segunda lista: ";
	cin >> max2;
	
	//Declarando os vetores
	int v1[max];
	
	//Inserindo os valores
	for (i = 0; i < max; i++){
		cout << i << "P: ";
		cin >> x;
		inserirSemRepetir(v1, x, qnt, max);
	}

	
}

void inserirSemRepetir(int v[], int x, int &pos, int max){
	int i;
	if (pos >= max){
		cout<< "Erro: Lista cheia!" << endl;
	} 
	else{
		for (i = 0; i < pos; i++){
			if(v[i] == x){
				cout << "Erro: Elemento repetido na posicao: " << i << endl << "Tente novamente: ";
				cin >> x;
				i = 0;
			}
		}
		v[pos] = x;
		pos++;
	}
}
